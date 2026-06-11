#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<ll> a, b;

int main(){
    int n;
    cin >> n;
    rep(i, n){
        ll c, d;
        cin >> c >> d;
        if (n%2 == 0) c *= 2, d *= 2;
        a.push_back(c);
        b.push_back(d);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll x, y;
    if (n%2==0){
        x = (a[n/2-1] + a[n/2]) / 2;
        y = (b[n/2-1] + b[n/2]) / 2;
    }
    else{
        x = a[n/2];
        y = b[n/2];
    }
    cout << y - x + 1 << endl;

    return 0;
}
