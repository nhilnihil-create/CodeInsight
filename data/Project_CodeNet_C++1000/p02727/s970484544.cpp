#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<pair<int, int>> p(a);
    int in;
    rep(i, a) {
        cin >> in;
        p[i] = make_pair(in, 0);
    }
    vector<pair<int, int>> q(b);
    rep(i, b) {
        cin >> in;
        q[i] = make_pair(in, 1);
    }
    vector<pair<int, int>> r(c);
    rep(i, c) {
        cin >> in;
        r[i] = make_pair(in, 2);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    vector<pair<int, int>> vec;
    vector<pair<int, int>> v;
    merge(p.begin(), p.end(), q.begin(), q.end(), back_inserter(v));
    merge(v.begin(), v.end(), r.begin(), r.end(), back_inserter(vec));
    reverse(vec.begin(), vec.end());
    int xcn = 0;
    int ycn = 0;
    int mcn = 0;
    int i = 0;
    ll sum = 0;
    while (true) {
        if (mcn + ycn + xcn == x + y)
            break;
        else if (vec[i].second == 0 && xcn < x) {
            sum += vec[i].first;
            xcn++;
        }
        else if (vec[i].second == 1 && ycn < y) {
            sum += vec[i].first;
            ycn++;
        }
        else if (vec[i].second == 2 && mcn + ycn + xcn < x + y) {
            sum += vec[i].first;
            mcn++;
        }
        i++;
    }
    cout << sum << endl;
}