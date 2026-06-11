#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
    
    int n;
    cin >> n;
    int ans = 0;
    while(n >= 500){
        n -= 500;
        ans += 1000;
    }
    while(n >= 5){
        n -= 5;
        ans += 5;
    }
    cout << ans << "\n";
}

