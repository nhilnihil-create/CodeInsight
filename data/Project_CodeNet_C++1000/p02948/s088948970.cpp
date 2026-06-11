#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> ab(N);
    for (ll i = 0; i < N; i++){
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    
    sort(ab.begin(), ab.end());

    priority_queue<ll, vector<ll>, less<ll>> c;

    ll cnt = 0;
    ll ans = 0;
    for(ll i = 1; i <= M; i++){
        for(; cnt < N; cnt++){
            if(ab.at(cnt).first > i) break;
            c.push(ab.at(cnt).second);
        }
        if(c.empty()) continue;
        ans += c.top();
        c.pop();
    }
    printf("%lld\n", ans);
    


}
