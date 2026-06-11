#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;

const ll MOD = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m+2);
    for(int i=1; i<=m; i++) cin >> a[i];
    a[0] = -1;
    a[m+1] = n+1;
    vector<ll> mfib(100001);
    mfib[0] = 1;
    mfib[1] = 1;
    for(int i=2; i<=100000; i++){
        mfib[i] = ((mfib[i-1]%MOD) + (mfib[i-2]%MOD))%MOD;
    }
    ll ans = 1;
    for(int i=0; i<=m; i++){
        int dif = a[i+1]-a[i]-2;
        if(dif==-1) {
            cout << 0 << endl;
            return 0;
        }
        ans *= mfib[dif];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}