#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int x, int y) {
    return (x % y ? gcd(y, x % y) : y);
}

int main(){

    int n;

    cin >> n;

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                ans += gcd(i+1, gcd(j+1, k+1));
            }
        }
    }

    cout << ans << endl;

    return 0;
} 
