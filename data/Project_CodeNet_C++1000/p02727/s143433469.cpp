#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    for (int i = 0; i < a; i++) cin >> p[i];
    vector<int> q(b);
    for (int i = 0; i < b; i++) cin >> q[i];
    vector<int> r(c);
    for (int i = 0; i < c; i++) cin >> r[i];
    
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    
    vector<int> z;
    for (int i = 0; i < x; i++) z.push_back(p[a - 1 - i]);
    for (int i = 0; i < y; i++) z.push_back(q[b - 1 - i]);
    
    sort(z.begin(), z.end());
    for (int i = 0; i < x + y; i++) {
        if (!r.empty() && r.back() > z[i]) {
            z[i] = r.back();
            r.pop_back();
        }
    }
    long s = 0;
    for (int x : z) {
        s += x;
    }
    cout << s << "\n";

    return 0;
}