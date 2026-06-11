//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    long double xx;
    xx = x/b*2.0;
    cout << fixed << setprecision(10);
    if(xx > a) {
        xx = a;
        long double bb = x/a;
        b = 2.0*b-bb*2.0;
    }

    cout << 180.0/M_PI * atan(b/xx) << endl;
}