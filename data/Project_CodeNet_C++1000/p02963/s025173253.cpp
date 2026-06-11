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


//x1*y2 - x2*y1 = S
//x1 = 1e9, y2 = 1e9
//x2 = 1    y1 = ?
int main() {
    io_init;
    ll S;
    cin >> S;
    if (S == 1e18) {
        cout << 0 << " " << 0 << " " << 1e9 << " " << 0 << " " << 1e9 << " " << 1e9 << endl;
        return 0;
    }
    ll x1, x2, y1, y2;
    x1 = 1e9;
    x2 = 1;
    y2 = (S+1e9 - 1) / 1e9;
    y1 = x1 * y2 - S;
    //cout << x1 * y2 - x2 * y1 << endl;
    cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
