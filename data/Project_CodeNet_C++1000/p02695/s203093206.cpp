#include <bits/stdc++.h>
using namespace std;

struct info {
    int a, b, c, d;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<info> v(q);
    for (int i = 0; i < q; i++) {
        info in;
        cin >> in.a >> in.b >> in.c >> in.d;
        v[i] = in;
    }
    queue<vector<int>> que;
    que.push({1});
    int cur_mx = 0;
    while (!que.empty()) {
        vector<int> front = que.front();
        que.pop();
        int sz = front.size();
        if (sz == n) {
            int score = 0;
            for (int i = 0; i < q; i++) {
                int a = v[i].a;
                int b = v[i].b;
                int c = v[i].c;
                int d = v[i].d;
                if (front[b - 1] - front[a - 1] == c) {
                    score += d;
                }
            }
            cur_mx = max(cur_mx, score);
        } else {
            int last = front[sz - 1];
            for (int i = last; i <= m; i++) {
                vector<int> nw = front;
                nw.push_back(i);
                que.push(nw);
            }
        }
    }
    cout << cur_mx;
    return 0;
}