#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n, k, r, s, p;
string t, u;

int main() {
    cin >> n >> k >> r >> s >> p >> t;
    int scr = 0;
    rep(i, n) {
        if (i < k) {
            if (t[i] == 'r') {
                scr += p;
                u.push_back('p');
            } else if (t[i] == 's') {
                scr += r;
                u.push_back('r');
            } else if (t[i] == 'p') {
                scr += s;
                u.push_back('s');
            }
        } else {
            if (t[i] == 'r') {
                if (u[i-k] != 'p') {
                    scr += p;
                    u.push_back('p');
                } else {
                    if (i+k < n) {
                        u.push_back(t[i+k]);
                    }
                }
            } else if (t[i] == 's') {
                if (u[i-k] != 'r') {
                    scr += r;
                    u.push_back('r');
                } else {
                    if (i+k < n) {
                        u.push_back(t[i+k]);
                    }
                }
            } else if (t[i] == 'p') {
                if (u[i-k] != 's') {
                    scr += s;
                    u.push_back('s');
                } else {
                    if (i+k < n) {
                        u.push_back(t[i+k]);
                    }
                }
            }
        }
    }
    cout << scr << endl;
}