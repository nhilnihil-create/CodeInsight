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
    int n,l,ans;
    cin >> n >> l;
    if(l>0){
        ans = (l+2-1 + l+n-1) * (n - 1) / 2;
    } else if(l+n-1<0){
        ans =(l+1-1 + l+n-2) * (n-1) / 2;
    } else {
        ans = (l+1-1 + l+n-1) * n / 2;
    }
    cout << ans << endl;
    return 0;
}
