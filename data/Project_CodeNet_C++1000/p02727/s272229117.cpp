#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define all(x) x.begin(), x.end()

vector<int> p[3];

int X, Y, n[3];

typedef long long ll;

ll res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> X >> Y >> n[0] >> n[1] >> n[2];
    for (int i = 0; i < 3; i++) {
        p[i].assign(n[i], 0);
        for (auto &x : p[i]) cin >> x;
        sort(all(p[i]));
        reverse(all(p[i]));
    }
    int cnt[] = {0, 0, 0}; int top[] = {X, Y, X + Y};
    for (int i = 1; i <= X + Y; i++) {
        int v = -1, k = 0;
        for (int j = 0; j < 3; j++) {
            if (cnt[j] >= top[j]) continue;
            if (p[j][cnt[j]] > v)
                v = p[j][cnt[j]], k = j;
        }
        res += v;
        cnt[k] += 1;
    }
    cout << res << endl;
    return 0;
}
