#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;

int main() {
    int n,a;
    cin >> n >> a;
    int b[n];
    rep(i,n) b[i] = a+i;
    int s = 0;
    rep(i,n) s += b[i];
    int c[n];
    rep(i,n) c[i] = s-b[i];
    int ans = 1000000;
    rep(i,n) {
        if (abs(s-c[i]) < abs(s-ans)) {
            ans = c[i];
        }
    }
    cout << ans << endl;
    return 0;
}