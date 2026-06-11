#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

struct vec {
    ll x, y;
    vec(ll x, ll y) : x(x), y(y) {}
    vec operator+(const vec& v) const {
        return vec(x + v.x, y + v.y);
    }
    vec operator-(const vec& v) const {
        return vec(x - v.x, y - v.y);
    }

    // 偏角の比較
    bool operator<(const vec &v) const {
        if (*this == v) return false;
        if (y > 0 && v.y > 0) {
            if ((x > 0 && v.x > 0) || (x < 0 && v.x < 0)) return y * v.x < x * v.y;
            if (x <= 0 && v.x >= 0) return false;
            return true;
        }
        else if (y < 0 && v.y < 0) {
            if ((x < 0 && v.x < 0) || (x > 0 && v.x > 0)) return y * v.x < x * v.y;
            if (x >= 0 && v.x <= 0) return false;
            return true;
        }
        else if (y > 0 && v.y < 0) {
            return true;
        }
        else if (y < 0 && v.y > 0) {
            return false;
        }
        else if (y == 0 && x > 0 && (v.y != 0 || (v.y == 0 && v.x < 0))) {
            return true;
        }
        else if (y == 0 && x < 0 && v.y < 0) {
            return true;
        }
        else if (v.y == 0 && v.x < 0 && y > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream &os, const vec &v) {
        return os << "[" << v.x << "," << v.y << "]";
    }
    bool operator==(const vec &v) const {
        return x * v.y == y * v.x && x * v.x >= 0 && y * v.y >= 0;
    }
};

int main() {
    int n; cin >> n;
    vector<vec> p;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x == 0 && y == 0) continue;
        p.push_back(vec(x, y));
    }
    sort(p.begin(), p.end());
    ll ans = 0;
    for (int i = 0; i < p.size(); i++) {
        vec s(0, 0);
        for (int j = i; j < p.size(); j++) {
            s = s + p[j];
            ans = max(ans, s.x * s.x + s.y * s.y);
        }
        for (int j = 0; j < i; j++) {
            s = s + p[j];
            ans = max(ans, s.x * s.x + s.y * s.y);
        }
    }
    printf("%.15f\n", sqrt(ans));
    return 0;
}