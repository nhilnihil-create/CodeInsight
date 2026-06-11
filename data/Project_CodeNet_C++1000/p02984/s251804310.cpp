#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll S = 0;
    rep(i,n) {
        cin >> a[i];
        S += a[i];
    }
    ll x1 = S;
    for(int i = 2; i <= n - 1; i += 2){
        x1 -= (2 * a[i - 1]);
    }
    cout << x1 << " ";

    ll prev_x = x1;
    for(int i = 2; i <= n; i++){
        ll xi = 2 * a[i - 2] - prev_x;
        cout << xi << " ";
        prev_x = xi;
    }
    cout << endl;
    return 0;
}
