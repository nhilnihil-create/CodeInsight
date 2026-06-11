#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vi x(n), l(n);
    rep(i,n){
        cin >> x[i] >> l[i];
    }

    vector<P> vec(n);
    rep(i,n){
        int s = x[i] - l[i];
        int g = x[i] + l[i];
        vec[i].first = g;
        vec[i].second = s;
    }
    sort(vec.begin(), vec.end());

    int cur = -1e9;
    int ans = 0;
    rep(i,n){
        if (vec[i].second >= cur){
            cur = vec[i].first;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
