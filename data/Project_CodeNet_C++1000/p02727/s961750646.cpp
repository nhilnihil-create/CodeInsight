#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 100005
#define ll long long

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "
#else
#define debug(x) ;
#endif

int x, y, a, b, c;
int p[maxn], q[maxn], r[maxn];
vector<int> ans, co;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> r[i];
    }
    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c);
    for (int i = a - x; i < a; i++) {
        ans.push_back(p[i]);
    }
    for (int i = b - y; i < b; i++) {
        ans.push_back(q[i]);
    }
    sort(ans.begin(), ans.end());
    int ri = c - 1;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] < r[ri]) {
            ans[i] = r[ri--];
        }
    }
    ll s = 0;
    for (int i = 0; i < ans.size(); i++) {
        s += ans[i];
    }
    cout << s;
    return 0;
}