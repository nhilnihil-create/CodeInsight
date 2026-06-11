#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

typedef long long ll;
const ll MOD = 998244353;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll n,s;
map<ll,ll> mm;
map<ll,ll> mm2;

ll pow(ll a, ll b) {
    if(mm.find(b) != mm.end()){
        return mm[b];
    }

  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    ll d = pow(a, b / 2);
    mm[b] = (d * d) % MOD;
    return mm[b];
  } else {
    ll d = pow(a, b - 1);
    mm[b] = (a * d) % MOD;
    return mm[b];
  }
}

int main(){
    cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll dp[n+1][s+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = 0;
        }
    }
    
    dp[0][0] = pow(2L,n);
    ll inv = pow(2L, MOD-2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= s; j++){
            if(j+a[i] <= s && dp[i][j] > 0){
                dp[i+1][j+a[i]] += dp[i][j]*inv;
                dp[i+1][j+a[i]] %= MOD;
            }
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
        }
    }

    cout << dp[n][s]%MOD << endl;

    return 0;
}