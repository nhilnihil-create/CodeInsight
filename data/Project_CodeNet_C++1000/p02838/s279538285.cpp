// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

ll power(ll m, ll n){
    if(n == 0) return 1;
    if(n % 2 == 1) return m * power(m, n - 1) % INF;
    if(n % 2 == 0) {
        ll tmp = power(m, n/2);
        return tmp * tmp % INF;
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), digit(64, 0);
    rep(i, N) cin >> A[i];

    rep(i, N){
        bitset<64> s(A[i]);
        rep(j, 64){
            if(s.test(j)) digit[j]++;
        }
    }

    ll ans = 0;

    rep(i, N){
        bitset<64> s(A[i]);
        ll a = 1;
        rep(j, 64){
            if(s.test(j)){
                ans += a * (N - digit[j]);
                ans %= INF;
            } else {
                ans += a * digit[j];
                ans %= INF;
            }
            a *= 2;
            a %= INF;
        }
    }

    ans *= power(2, INF - 2);
    ans %= INF;

    cout << ans << endl;
    
}