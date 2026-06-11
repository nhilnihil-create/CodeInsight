#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll times = x/d;
    if (k <= abs(times)) {
        cout << x - d*k << endl;
        return 0; 
    }
    if ((k-times)%2==0) {
        cout << x%d << endl;
    } else {
        cout << abs(x%d - d) << endl;
    }
    return 0;
}