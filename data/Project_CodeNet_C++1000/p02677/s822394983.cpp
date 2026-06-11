#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    doublecout(abs(polar(a, (h / 6.0 + m / 360.0) * M_PI) - polar(b, m * M_PI / 30.0)));
    return 0;
}
