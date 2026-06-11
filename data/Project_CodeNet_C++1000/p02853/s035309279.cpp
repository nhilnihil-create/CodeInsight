#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int X,Y;
    cin >> X >> Y;
    
    int ans = 0;
    if(X<=3) ans += (4-X)*100000;
    if(Y<=3) ans += (4-Y)*100000;
    if(X == 1 && Y == 1) ans += 400000;
    
    cout << ans << endl;
    return 0;
}
