#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct loop {
    lint loop_len;
    lint prefix_len;
};

lint n, k;
vector<int> a;

int f(int p) {
    return a[p];
}

int simple_solve(int start, int m) {
    int now = start;
    for (int i = 0; i < m; i++) {
        now = f(now);
    }
    return now;
}

loop get_loop() {
    int now = 0;
    int time = 0;
    vector<int> appear_time(n, -1);
    while (true) {
        if (appear_time[now] == -1) {
            appear_time[now] = time;
            time++;
            now = f(now);
        } else {
            loop res;
            res.prefix_len = appear_time[now];
            res.loop_len = time - res.prefix_len;
            return res;
        }
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    auto lp = get_loop();
    if (k < lp.prefix_len) {
        cout << simple_solve(0, k) + 1 << endl;
    } else {
        lint loop_num = (k - lp.prefix_len) / lp.loop_len;
        lint essential = k - loop_num * lp.loop_len;
        cout << simple_solve(0, essential) + 1 << endl;
    }
}