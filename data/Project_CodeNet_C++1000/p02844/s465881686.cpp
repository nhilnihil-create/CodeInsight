#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string s;
    cin >> N >> s;

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                bool judge0 = 0, judge1 = 0, judge2 = 0;
                rep(l, N) {
                    if (!judge0 && s[l] - '0' == i)
                        judge0 = 1;
                    else if (!judge1 && judge0 && s[l] - '0' == j)
                        judge1 = 1;
                    else if (judge1 && s[l] - '0' == k)
                        judge2 = 1;
                }

                if (judge2) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}