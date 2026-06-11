#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double a_angle = 2 * acos(-1) * ((double)h + (double)m / (double)60) / (double) 12;
    double b_angle = 2 * acos(-1) * (double)m / (double)60;

    cout << fixed << setprecision(20) << sqrt(a * a + b * b - 2 * a * b * cos(abs(a_angle - b_angle))) << endl;
}