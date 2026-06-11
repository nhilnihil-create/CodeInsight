#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    int e = (m + 1) / 2;
    int o = m / 2;
    rep(i, e){
        a[i] = e - 1 - i;
        b[i] = e + i;
    }
    rep(i, o){
        a[e+i] = 2 * e + o - 1 - i;
        b[e+i] = 2 * e + o + 1 + i;
    }
    rep(i, m)cout << a[i]+1 << ' ' << b[i]+1 << endl;
}