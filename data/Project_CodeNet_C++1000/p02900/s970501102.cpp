#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void factorization(long long n,map<long long ,long long>& mp){
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n /= i;
        }
     }
     if(!(n == 1)) mp[n]++;
}
int main(){
    ll a, b;
    cin >> a >> b;
    ll tmp = gcd(a, b);
    map<ll, ll> mp;
    factorization(tmp, mp);
    ll res = 1;
    for(auto i:mp){
        res++;
    }
    cout << res << endl;
}