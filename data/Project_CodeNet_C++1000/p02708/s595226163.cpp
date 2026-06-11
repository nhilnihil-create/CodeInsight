#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for(ll i = k; i <= n+1; ++i){
        ans += n * (n+1) / 2 - (n-i) * (n-i+1) / 2 - (i-1) * i / 2 + 1;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}
