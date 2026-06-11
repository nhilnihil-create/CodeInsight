// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1001001001;
const ll LONGINF = 1001001001001001LL;
const ll MOD = 1000000007LL;

const double PI = acos(-1);
const double EPS = 1e-9;
int main() {
    int N; cin >> N;
    vector< pair<int, int> > points(N);
    for(int i=0; i<N; i++) {
        int x, y; cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    sort(points.begin(), points.end(), [](auto a, auto b) {
            double ra = atan2(a.second, a.first);
            double rb = atan2(b.second, b.first);
            return ra < rb;
        });
    for(int i=0; i<N; i++) points.emplace_back(points[i]);

    double ans = 0, cur = 0;
    ll x = 0, y = 0; int r = 0;
    for(int l=0; l<N; l++) {
        while(r < l + N) {
            ll nx = x + points[r].first;
            ll ny = y + points[r].second;
            if(cur > sqrt(nx*nx + ny*ny)) break;
            cur = sqrt(nx*nx + ny*ny);
            x = nx, y = ny;
            r++;
        }
        chmax(ans, cur);
        
        x -= points[l].first;
        y -= points[l].second;
        cur = sqrt(x*x + y*y);
    }
    printf("%.12f\n", ans);
    return 0;
}
