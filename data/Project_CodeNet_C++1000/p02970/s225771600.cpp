#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, d;
    cin >> n >> d;
    int divisor = 2 * d + 1;
    
    int ans = (n + divisor - 1) / divisor;
    cout << ans << endl;
    
}
