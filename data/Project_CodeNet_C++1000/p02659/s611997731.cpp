# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long
  
using namespace std;
  
const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int32_t main() {
    speed;
    long double a, b;
    cin >> a >> b;
    b = round(b * 100);
    cout << (int)(a * b / 100);
}
