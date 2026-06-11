#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    vector<ll> g(n+1, 0);
    ll MAX = 0;
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        g[a]++;
        MAX = max(MAX, a);
        if(i==0 && a!=0) ans = 0;
    }
    ll INF = 998244353;
    for(ll i = 1; i <= MAX; i++){
        for(ll j = 0; j < g[i]; j++)
            ans=(ans*g[i-1])%INF;
    }
    if(g[0]>1) ans = 0;
    cout << ans << endl;
   /* for(ll i = 0; i <= MAX; i++){
        if(g[i]==0)
        cout << i << " " << g[i] << endl;
    }*/
    return 0;
}
