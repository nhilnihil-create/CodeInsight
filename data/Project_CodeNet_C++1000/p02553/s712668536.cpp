#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
// using cplx = complex<double>;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MAXN 1000010
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep2(i, s, n) for(int i = (s); i < (int)(n); ++i)
const ll mod = 1e9 + 7;

template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

bool pairCompare(const P &firstElof, const P &secondElof) {
    return firstElof.second < secondElof.second;
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = a * c;
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << endl;
}
