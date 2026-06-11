#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    string s; cin >> s;

    for (int i = a; i < max(c, d); i++) {
        if (s[i] == '#' && s[i + 1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (c < d) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = b - 1; i < min(d, n - 2); i++) {
        if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
