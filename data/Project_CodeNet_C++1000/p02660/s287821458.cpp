#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    int ans = 0;
    for(int i=2; i*i<=n; i++){
        int ci = 0;
        while(n % i == 0){
            n /= i;
            ci++;
        }
        if(ci != 0){
            int tri = (-1.0 + sqrt(1.0+8.0*(ci+0.01)))/2.0;
            ans += tri;
        }
    }
    if(n != 1){
        ans++;
    }
    cout << ans << endl;
    return 0;
}