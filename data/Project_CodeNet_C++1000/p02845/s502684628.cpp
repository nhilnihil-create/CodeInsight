#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> c(n+1);
    c[0] = 3;
    ll ans = 1;
    rep(i, n) {
        if(!c[a[i]]) {
            puts("0");
            return 0;
        }
        ans = ans * c[a[i]] % mod;
        --c[a[i]];
        ++c[a[i]+1];
    }
    cout << ans << endl;
    return 0;
}
