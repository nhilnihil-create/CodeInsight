#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(void){
    int h, w, n;
    cin >> h >> w >> n;
    
    int divisor = max(h,w);
    int ans = (n + divisor - 1) / divisor;
    cout << ans << endl;
    
}
