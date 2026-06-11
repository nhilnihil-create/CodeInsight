#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    double ans;
    if (n%2) ans = (double) (n/2+1) / (double) n;
    else ans = 0.5;
    cout << setprecision(15) << ans << endl;
    return 0;
}
