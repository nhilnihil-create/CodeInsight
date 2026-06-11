#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll h,w,n;
    cin >> h >> w >> n;
    ll ans=0;
    if(h<w){
        ans=(n/w)+1;
        if(n%w==0) ans--;
    }
    else {
        ans=(n/h)+1;
        if(n%h==0) ans--;
    }
    cout << ans << endl;
}