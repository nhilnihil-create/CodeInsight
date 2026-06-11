#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double theta_a = 2 * M_PI * (60 * h + m) / (12 * 60);
    double theta_b = 2 * M_PI * m / 60;

    double x_a, x_b, y_a, y_b;
    x_a = a * sin(theta_a);
    y_a = a * cos(theta_a);
    x_b = b * sin(theta_b);
    y_b = b *cos(theta_b);

    double dx = x_b - x_a;
    double dy = y_b - y_a;
    double d = sqrt(dx * dx + dy * dy);

    cout << setprecision(20);
    cout << d << endl;

    return 0;
}