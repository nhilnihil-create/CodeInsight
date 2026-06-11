#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>
#define PI 3.14159265358979323846

int main() {
    int n;
    cin >> n;

    vector<Pll> eng;
    while (n--) {
        ll x, y;
        cin >> x >> y;
        if (x != 0 || y != 0) eng.emplace_back(x, y);
    }
    n = eng.size();
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++) {
        double x = eng[i].first, y = eng[i].second;
        double theta = atan(y / x);
        if (x < 0) theta += PI;
        if (x >= 0 && y < 0) theta += 2 * PI;
        v.emplace_back(theta, i);
    }
    sort(all(v));
    double mx = 0;
    for (int i = 0; i < n; i++) {
        double x = 0, y = 0;
        for (int j = i; j < i + n; j++) {
            int idx = v[j % n].second;
            x += eng[idx].first;
            y += eng[idx].second;
            mx = max(mx, sqrt(x*x + y*y));
        }
    }
    cout << fixed << setprecision(16) << mx << endl;
}
