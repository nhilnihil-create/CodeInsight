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
#include <functional>
using namespace std;
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
typedef pair<int, int> pii;
typedef long long ll;
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

typedef complex<double> P;
typedef pair<P, P> L;

signed main() {
    int N; cin >> N;
    queue<L> q;
    q.push(make_pair(P(0, 0), P(100, 0)));
    double theta = M_PI / 3.0;
    rep(k,0,N) {
        int cnt = 1LL << (2*k);
        while(cnt--) {
            L t = q.front(); q.pop();
            P vec = t.second - t.first;

            double x = vec.real() * cos(theta) - vec.imag() * sin(theta);
            double y = vec.real() * sin(theta) + vec.imag() * cos(theta);
            P rot(x, y);

            P ps[5];
            rep(i,0,5) {
                if(i <  2) ps[i] = t.first + i / 3.0 * vec;
                if(i == 2) ps[i] = t.first + 1.0 / 3.0 * vec + rot / 3.0;
                if(i >  2) ps[i] = t.first + (i-1) / 3.0 * vec;
            }
            rep(i,0,4) {
                q.push(make_pair(ps[i], ps[i+1]));
            }
        }
    }

    bool init = true;
    while(!q.empty()) {
        L t = q.front(); q.pop();
        if(init) printf("%.12f %.12f\n", t.first.real(), t.first.imag());
        printf("%.12f %.12f\n", t.second.real(), t.second.imag());
        init = false;
    }
    return 0;
}