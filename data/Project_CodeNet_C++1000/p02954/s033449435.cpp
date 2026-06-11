
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
const int N = 1e5;
int a[N];
int n, i1, i2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.length();
    s += ' ';
    bool r = true;
    int rcnt = 0, lcnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (r) {
            if (s[i] == 'R') {
                ++rcnt;
            } else { // 'L'
                i1 = i - 1;
                i2 = i;
                r = false;
                lcnt = 1;
            }
        } else {
            if (s[i] == 'L') {
                ++lcnt;
            } else {
                // do sth
                int ct = rcnt + lcnt;
                a[i1] = ct / 2;
                a[i2] = ct / 2;
                if (ct & 1) {
                    if (rcnt > lcnt) {
                        if (rcnt & 1)
                            ++a[i1];
                        else
                            ++a[i2];
                    } else if (rcnt < lcnt) {
                        if (lcnt & 1)
                            ++a[i2];
                        else
                            ++a[i1];
                    }
                }
                lcnt = 0;
                rcnt = 1;
                r = true;
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        cout << a[j] << ' ';
    }
    cout << endl;

    return 0;
}

