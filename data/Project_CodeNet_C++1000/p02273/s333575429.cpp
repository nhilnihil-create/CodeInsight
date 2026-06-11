#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

struct p {
    double x;
    double y;
};

void kock(int n, p p1, p p2) {
    if (n == 0) {
        return;
    }

    p s = {(2.0 * p1.x + p2.x) / 3.0, (2.0 * p1.y + p2.y) / 3.0};
    p t = {(p1.x + 2.0 * p2.x) / 3.0, (p1.y + 2.0 * p2.y) / 3.0};
    p u = {(t.x - s.x) * cos(60 * M_PI / 180) -
               (t.y - s.y) * sin(60 * M_PI / 180) + s.x,
           (t.x - s.x) * sin(60 * M_PI / 180) +
               (t.y - s.y) * cos(60 * M_PI / 180) + s.y};
    kock(n - 1, p1, s);
    cout << fixed << setprecision(10) << s.x << " " << s.y << endl;
    kock(n - 1, s, u);
    cout << fixed << setprecision(10) << u.x << " " << u.y << endl;
    kock(n - 1, u, t);
    cout << fixed << setprecision(10) << t.x << " " << t.y << endl;
    kock(n - 1, t, p2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << fixed << setprecision(10) << 0.0 << " " << 0.0 << endl;
    kock(N, {0, 0}, {100, 0});
    cout << fixed << setprecision(10) << 100.0 << " " << 0.0 << endl;
    return 0;
}

