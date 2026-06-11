#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<n; i++){
        ans += ((min(n-1, i*i)/i)*2);
        if(i*i < n){
            ans -= 1;
        }
    }
    cout << ans;
    return 0;
}