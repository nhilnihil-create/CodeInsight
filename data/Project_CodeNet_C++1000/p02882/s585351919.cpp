#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    double water = x / a;
    double s = a * b;
    double rad;
    if ((s / 2) > water)
    {
        double tmp = (b * b) / (water * 2);
        rad = atan(tmp);
    }
    else
    {
        double tmp = 2 * (s - water) / (a * a);
        rad = atan(tmp);
    }
    double ans = rad * (180 / M_PI);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};