#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int n, m; // 変数
ll a;
double b;

int main() {
// input
    // cin >> a >> b;
    cin >> a;
    string s;
    cin >> s;
    ll b = 0;
    b += (s[0] - '0') * 100;
    b += (s[2] - '0') * 10;
    b += (s[3] - '0');
// solve
// output
    // cout << (a * (ll)(b * 100 + 0.001) / 100) << "\n";
    cout << (a * b / 100) << "\n";
}