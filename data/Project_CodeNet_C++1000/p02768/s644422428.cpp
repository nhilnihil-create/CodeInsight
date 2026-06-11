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

ll exp(ll m, ll n){
    if(n == 0) return 1;
    else if (n % 2 == 1) return (m * exp(m, n - 1)) % INF;
    else {
        ll tmp = exp(m, n/2);
        return tmp * tmp % INF;
    }
}


ll nCa(ll n, ll a){
    ll num = 1, den = 1;
    for(ll i = n - a + 1; i <= n; i++){
        num = num * i % INF;
    }
    for(ll i = 1; i <= a; i++){
        den = den * i % INF;
    }
    return num * exp(den, INF - 2) % INF;
}

int main(){
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = (exp(2, N) - nCa(N, A)- nCa(N, B) - 1) % INF;
    if(ans < 0) ans += INF;
    cout << ans << endl;
}