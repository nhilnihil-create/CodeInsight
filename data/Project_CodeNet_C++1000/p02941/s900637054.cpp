#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
int n;
num a[nsz + 5], b[nsz + 5], ans;
priority_queue<pair<num, int>> q;

int inline pre(int id) {
    return id != 1 ? id - 1 : n;
}

int inline nxt(int id) {
    return id != n ? id + 1 : 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> a[i];
    }
    cont (i, n) {
        cin >> b[i];
        if (a[i] != b[i]) {
            q.push(make_pair(b[i], i));
        }
    }
    for (; !q.empty();) {
        int id = q.top().second;
        num cur = q.top().first;
        q.pop();
        num del = b[pre(id)] + b[nxt(id)], cnt = max(1LL, (b[id] - a[id]) / del);
        ans += cnt;
        b[id] = cur - cnt * del;
        if (a[id] > b[id]) {
            ans = -1;
            break;
        } else if (a[id] != b[id]) {
            q.push(make_pair(b[id], id));
        }
    }
    cout << ans << ln;
}
