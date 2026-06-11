#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, MAX = 0; cin >> N;
    multiset<ll> ST;
    set<ll> ban;
    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        MAX = max(MAX, x);
        if(ST.find(x) != ST.end()) ban.insert(x);
        ST.insert(x);
    }
    for(auto x : ST){
        ll i = 2;
        while(x*i <= MAX){
            ST.erase(x*i);
            i++;
        }
    }
    for(auto x : ban) ST.erase(x);
    cout << ST.size() << endl;

}