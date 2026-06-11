#include <bits/stdc++.h>

using namespace std;
using std::cin;
using std::cout;
vector<int> v;
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
const int mn = 505;
int a[mn][mn];

void draw(vector<int> v, int depth) {
    if (sz(v) == 1) return;
    vector<int> l, r;
    for (int i = 0; i < sz(v); i++) {
        if (i % 2) l.pb(v[i]);
        else r.pb(v[i]);
    }
    for (int i = 0; i < sz(l); i++) {
        for (int j = 0; j < sz(r); j++) {
            a[l[i]][r[j]] =
            a[r[j]][l[i]] = depth;
        }
    }
    draw(l, depth + 1);
    draw(r, depth + 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) v.pb(i);
    draw(v, 1);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][n]);
    }
}