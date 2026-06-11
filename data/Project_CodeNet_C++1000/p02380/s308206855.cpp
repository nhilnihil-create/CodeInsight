#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
#define INF (1<<30)

typedef long long ll;

using namespace std;

void solve(){
    double a, b, C;
    double S, L, h;

    cin >> a >> b >> C;

    S = 0.5 * a * b * sin(M_PI/(180.0/C));
    L = sqrt(pow(a, 2)+pow(b, 2)-2*a*b*cos(M_PI/(180.0/C)))+a+b;
    h = S/a*2;

    cout.precision(15);
    cout << fixed;
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
