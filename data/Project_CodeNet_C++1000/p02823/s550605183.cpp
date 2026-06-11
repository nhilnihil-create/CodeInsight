#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
    ll n, a, b, i;
    cin >> n >> a >> b;

    if (abs(a-b) % 2 == 0) {
        i = abs(a-b) / 2;
    } else {
        ll d = min((a-1)+(b-1), (n-a)+(n-b));
        i = (d + 1) / 2;
    }
    cout << i << endl;
    
    return 0;
}