#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main() {
    io_init;
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    else {
        ll ans = 0;
        for (ull k = 5; k <= N; k *= 5) {
            ans += (N / k)/2;
        }
        cout << ans << endl;
    }
    
}
