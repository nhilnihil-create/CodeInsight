#include <algorithm>
#include <iostream>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

class Ball {
    public:
        Ball(ll _x, ll _y) : x(_x), y(_y) {
        }

        ll x;
        ll y;
};

class Line {
    public:
        Line(Ball _a, Ball _b) : a(_a), b(_b) {
        }
        Ball a;
        Ball b;

        ll diff_x() const {
            return b.x - a.x;
        }

        ll diff_y() const {
            return b.y - a.y;
        }

        ll slope() const {
            return diff_y() / diff_x();
        }
};

const ll INF = LONG_LONG_MAX / 2;

vector<pair<ll, ll>> balls;
vector<Line> lines;

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
}

int solve(const int N) {
    vector<pair<ll, ll>> slopes;
    for (int i = 0; i < (int) lines.size(); i++) {
        auto &line = lines[i];
        slopes.push_back({line.diff_x(), line.diff_y()});
    }

    sort(slopes.begin(), slopes.end());
    auto prev = slopes[0];
    // printf("(%d, %d)\n", slopes[0].first, slopes[0].second);
    int ans = 1;
    int cnt = 1;
    for (int i = 1; i < (int) slopes.size(); i++) {
        // printf("(%d, %d)\n", slopes[i].first, slopes[i].second);
        if (slopes[i] == prev) {
            cnt++;
        } else {
            // printf("ans=%d, cnt=%d\n", ans, cnt);
            chmax(ans, cnt);
            prev = slopes[i];
            cnt = 1;
        }
    }
    // printf("ans=%d, cnt=%d\n", ans, cnt);
    chmax(ans, cnt);
    return N - ans;
}

int main(void) {
    int N;
    cin >> N;

    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }

    balls.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        balls[i] = {x, y};
    }
    sort(balls.begin(), balls.end());

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Ball a(balls[i].first, balls[i].second);
            Ball b(balls[j].first, balls[j].second);
            lines.push_back(Line(a, b));
        }
    }

    // for (auto &l : lines) {
    //     printf("(%d, %d) - (%d, %d)\n", l.a.x, l.a.y, l.b.x, l.b.y);
    // }

    cout << solve(N) << endl;

    return 0;
}
