#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


template<class T>
vector<T> cumsum1d(const vector<T> &v){
    int size = v.size();
    vector<T> cum(size+1,0);
    for(int i = 0; i < size; i++){
        cum[i+1] = v[i] + cum[i];
    }
    return cum;
}

int main() {
    ll n, num;
    cin >> n >> num;

    vector<ll> p(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<ll> group(n, -1);
    vector<vector<ll>> loops(n);
    ll group_id = 0;
    for(int i = 0; i < n; i++){
        ll idx = i;
        if(group[idx] != -1){continue;}

        while(group[idx] == -1){
            group[idx] = group_id;
            loops[group_id].push_back(c[idx]);
            idx = p[idx];
        }
        group_id++;
    }

    for(int i = 0; i < group_id; i++){
        int lim = loops[i].size();
        for(int j = 0; j < lim; j++){
            loops[i].push_back(loops[i][j]);
        }
    }

    vector<vector<ll>> loops2(group_id);
    for(int i = 0; i < group_id; i++){
        loops2[i] = cumsum1d(loops[i]);
    }

    vector<ll> loop_sum(group_id, 0);
    for(int i = 0; i < group_id; i++){
        loop_sum[i] = loops2[i][loops[i].size()/2];
    }

    ll ans = -1e9-1;
    for(int i = 0; i < group_id; i++){
        ll size =  loops[i].size()/2;
        for(int j = 0; j < size; j++){
            for(int k = j+1; k < j+1 + size; k++){
                if(num < k-j){continue;}
                ll tmpsum = loops2[i][k] - loops2[i][j];
                ans = max(ans, tmpsum);
                if(loop_sum[i] > 0){
                    ans = max(ans, tmpsum + (num - (k-j))/size*loop_sum[i]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
