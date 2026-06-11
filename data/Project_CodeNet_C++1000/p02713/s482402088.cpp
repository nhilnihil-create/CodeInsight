#include <bits/stdc++.h>
using namespace std;
int a, b, c, x;
int ans=0;
int main() {
    cin >> x;
    for (int i=1; i<=x; i++) {
        for (int j=1; j<=x; j++) {
            for (int k=1; k<=x; k++) {
                ans+=gcd(i, gcd(j, k));
            }
        }
    }
    
    cout << ans;
}