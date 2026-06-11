#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;
const ll MOD = 1e9+7;

vector<vector<ll>> com(20020, vector<ll>(2020,0));
void COM() {
    com[0][0] = 1;
    for (int i = 1; i < 2020; i++) {
        com[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            com[i][j] = (com[i-1][j-1] + com[i-1][j]) % MOD;
        }
    }
}

int main(){
    ll n, k; cin >> n >> k;
  	COM();
    loop(i,1,k+1){
        ll ans;
        if(n-k+1 >= i) ans = (com[n-k+1][i]*com[k-1][i-1]) % MOD;
        else ans = 0;
        cout << ans << endl;
    }
}