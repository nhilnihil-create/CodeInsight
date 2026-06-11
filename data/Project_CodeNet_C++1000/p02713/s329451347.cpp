#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int k;
    cin >> k;

    long long int ans = 0;
    for(int a=1; a<=k; a++){
        for(int b=1; b<=k; b++){
            for(int c=1; c<=k; c++){
                ans += gcd(gcd(a,b), c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}