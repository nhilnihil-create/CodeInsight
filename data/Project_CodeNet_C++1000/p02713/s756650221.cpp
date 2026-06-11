#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(void){
    long long k;
    cin >> k;
    long long ans = 0;
    
    for (int a = 1; a <= k; a++){
        for (int b = 1; b <= k; b++){
            for (int c = 1; c <= k; c++){
                long long temp = GCD(b,c);
                ans += GCD(a,temp);
            }
        }
    }
    
    cout << ans << endl;
}
