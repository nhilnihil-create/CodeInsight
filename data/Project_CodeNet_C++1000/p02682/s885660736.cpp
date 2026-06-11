#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int count = k;
    int ans = 0;
    if(k == 1){
        if(a == 0 && b == 0) cout << -1 << endl;
        else if(a == 0) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    if(a > k){
        ans = k;
        cout << ans << endl;
        return 0;
    }
    ans += a;
    count = k - a;
    // cout << ans << endl;
    if(count > 0) count -= b;
    // cout << count << endl;
    if(count > 0){
        ans -= count;
    }
    // if(ans < 0) cout << 0 << endl;
    // else cout << ans << endl;
    cout << ans << endl;
    return 0;
}