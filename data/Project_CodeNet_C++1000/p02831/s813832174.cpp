#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    int mn = min(a,b);
    int mx = max(a,b);
    //cout << mn << endl;
    
    ll ans = mn;
    while(ans % mx != 0) {
        ans += mn;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
