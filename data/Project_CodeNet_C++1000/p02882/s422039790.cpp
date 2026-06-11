#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstring>
#include<string>
#include<set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll = long long int;

const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void) {
    long double a, b, x, thita; cin >> a >> b >> x;
    if (x > 0.5 * a * a * b) {
        thita = atan((2 * (a * a * b - x)) / (a * a * a));
    }
    else {
        thita = M_PI / 2 - atan((2 * x) / (a * b * b));
    }
    cout << fixed << setprecision(7) << (thita * 180) / M_PI << endl;
}