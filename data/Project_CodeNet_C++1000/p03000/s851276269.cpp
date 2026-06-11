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
    int n,x,ans;
    cin >> n >> x;
    ans = 1;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int pre = 0;
    for(int i = 1; i<= n; i++){
        int d = pre + l[i-1];
        if(d <= x) ans++;
        pre = d;
    }
    cout << ans << endl;
    return 0;
}
