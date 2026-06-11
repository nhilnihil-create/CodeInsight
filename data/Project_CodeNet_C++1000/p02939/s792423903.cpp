#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int res = 0;
    bool judge = 1;
    char prev = '?';
    rep(i, s.size()) {
        if (prev != s[i])
            res++, judge = 1;
        else {
            if (judge) {
                i++;
                if (i >= s.size())
                    break;
                res++;
                judge = 0;
            } else {
                res++;
                judge = 1;
            }
        }
        prev = s[i];
    }

    cout << res << endl;
}