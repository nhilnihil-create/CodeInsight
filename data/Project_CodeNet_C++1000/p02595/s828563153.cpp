#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll n, d, ans = 0;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        if (a*a+b*b <= d*d) {
            ans ++;
        }
    }
    cout << ans << endl;
}