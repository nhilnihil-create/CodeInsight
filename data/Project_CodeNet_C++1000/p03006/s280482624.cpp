#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF =ll(1e18) +5;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> X;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >>b;
        X.emplace_back(a,b);
    }
    sort(X.begin(),X.end());
    map<pair<ll,ll>,ll> mp;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ll dx = X[j].first - X[i].first;
            ll dy = X[j].second -X[i].second;
            mp[make_pair(dx,dy)]++;
        }
    }
    ll ans = 0;
    for(auto itr = mp.begin();itr!=mp.end();++itr){
        ans = max(ans,(itr->second));
    }
    cout << N-ans << endl;


    return 0;
}