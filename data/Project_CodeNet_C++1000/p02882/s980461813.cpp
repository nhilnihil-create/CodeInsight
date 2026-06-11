#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    if (x <= a * a * b / 2.0) {
        cout << fixed << setprecision(10) << atan(a * b * b / 2.0 / x) * 180 / acos(-1) << endl;
    } else {
        cout << fixed << setprecision(10) << atan(2.0 * b / a - 2.0 * x / a / a / a) * 180 / acos(-1) << endl;
    }
}