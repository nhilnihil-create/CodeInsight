#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e12);
const ll mod = ll(1e9) + 7;
const double pi = acos(-1);
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
#define yes pf("Yes")
#define no pf("No")

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n){
        t *= i;
        t %= mod;
    }
    return t;
}

ll power(ll a, ll b){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = power(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}

ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = 1;
    for(ll i = 0; i < b; i++) {
        ans *= (a - i);
        ans /= (i + 1);
        ans %= mod;
    }
    return ans;
}


int main(){
    string s;
    cin >> s;
    ll dp[100001][13];
    rep0(i, 100001)rep0(j, 13)dp[i][j] = 0;
    dp[0][0] = 1;
    rep0(i, s.size()){
        if(s[i] == '?'){
            rep0(j, 13){
                rep0(k, 10){
                    dp[i + 1][(j * 10 + k) % 13] += dp[i][j];
                }
            }
        }else{
            rep0(j, 13){
                dp[i + 1][(j * 10 + s[i] - 48) % 13] += dp[i][j];
            }
        }
        rep0(j, 13)dp[i + 1][j] %= mod;
    }
    pf(dp[s.size()][5]);
    return 0;
}

