#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    vector<pair<ll,ll>> P(N),memo;
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        P[i]=make_pair(x,y);
    }
    map<pair<ll,ll>,ll> mp;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ll dx = P[i].first-P[j].first;
            ll dy = P[i].second-P[j].second;
            mp[make_pair(dx,dy)]++;
            memo.push_back(make_pair(dx,dy));
            mp[make_pair(-dx,-dy)]++;
            memo.push_back(make_pair(-dx,-dy));
        }
    }
    ll cnt = -INF;
    for(int i=0;i<memo.size();i++){
        cnt = max(cnt,mp[memo[i]]);
    }
    cout << N-cnt << endl;
    return 0;
}