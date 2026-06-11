#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }
 
int main(){
    ll L, R;
    cin >> L >> R;
    ll ans = 2019;
    if(R-L+1>2019){
        cout << 0 << endl;
        return 0;
    }
    else{
        for(ll i=L; i<R; ++i){
            for(ll j=i+1; j<=R; ++j){
                ans = min(ans, (i*j)%2019);
            }
        }
    }
    cout << ans << endl;
    return 0;
}