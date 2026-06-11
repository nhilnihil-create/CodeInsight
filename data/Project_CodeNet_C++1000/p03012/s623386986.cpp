#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    int r,l = 0; int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        l+= a[i];
    }
    int ans = 200;
    for(int i = 0;i < n;i++){
        ans = min(ans,abs(r-l));
        r+=a[i];
        l-=a[i];
    }
    cout << ans;
}
