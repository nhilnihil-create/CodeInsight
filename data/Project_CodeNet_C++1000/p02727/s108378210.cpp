//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < A; i++) {
        int a; cin >> a;
        pq.push(make_pair(a, 0));
    }
    for (int i = 0; i < B; i++) {
        int a; cin >> a;
        pq.push(make_pair(a, 1));
    }
    for (int i = 0; i < C; i++) {
        int a; cin >> a;
        pq.push(make_pair(a, 2));
    }

    int x = 0, y = 0, sum = 0;
    long long ans = 0;
    while (sum < X+Y) {
        pair<int, int> p = pq.top();
        pq.pop();
        if (p.second == 0) {
            x++;
            if (x > X) continue;
        }
        if (p.second == 1) {
            y++;
            if (y > Y) continue;
        }
        ans += p.first;
        sum++;
        //cout << p.first << " " << x << " " << y << " " << sum << endl;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}