#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, a;
    cin >> n;
    string s;
    cin >> s;
    rep(i, s.size()) {
        a = (s[i] - 'A');
        a = (a + n) % 26;
        putchar(a + 'A');
    }
    cout << endl;
    return 0;
}