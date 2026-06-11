#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
    IOS;
    int n;
    cin >> n;
    int ans = 0;
    int p = 100;
    while(1){
        if(p >= n)
            break;
        p += p/100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

