#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    vector<pair<ll, ll>> range(N);
    for(int i=0; i<N; i++){
        ll X, L;
        cin >> X >> L;
        range[i]={X+L, X-L};
    }
    sort(all(range));
    ll ans=0, cur=-1e9-5;
    for(int i=0; i<N; i++){
        if(cur <= range[i].second){
            cur=range[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}