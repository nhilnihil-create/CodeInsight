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
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    int ans = 0, k = 0, prevh = -1;
    rep(i, n){
        if(prevh >= h[i]){
            k++;
            if(i == n - 1){
                ans = max(ans,k);
            }
        } else {
            ans = max(ans, k);
            k = 0;
        }
        prevh = h[i];
    }
    cout << ans << endl;

    return 0;
}
