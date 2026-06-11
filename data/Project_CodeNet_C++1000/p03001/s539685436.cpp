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
    ll w,h,x,y;
    bool hasMulti = false;
    cin >> w >> h >> x >> y;
    if(w%2==0 && w/2==x && h%2==0 && h/2 == y){
        hasMulti = true;
    }
    double ans;
    ans = (double)w * h / 2;
    cout << fixed << setprecision(15) << ans << " ";
    if(hasMulti){
        cout << 1;
    } else {
        cout << 0;
    }
    cout << endl;
    return 0;
}
