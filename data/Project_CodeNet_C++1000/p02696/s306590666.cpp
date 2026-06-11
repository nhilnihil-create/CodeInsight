#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000
#define mod 1000000007

using namespace std;

signed main(){
    int a, b, n;
    cin >> a >> b >> n;
    int x;
    if (b-1 <= n){
        x = b-1;
    } else {
        x = n;
    }
    int ans = a*x/b-a*(x/b);
    cout << ans << endl;
    return 0;
}





















