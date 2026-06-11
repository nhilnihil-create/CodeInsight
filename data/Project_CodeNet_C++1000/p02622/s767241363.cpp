#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s.at(i) != t.at(i))
            cnt++;
    }
    cout << cnt << endl;
}
