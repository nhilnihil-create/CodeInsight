#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll K, X;
    cin >> K >> X;
    ll s = X - K + 1;
    ll e = X + K - 1;
    for (ll i = s; i <= e; ++i) {
        cout << i << " ";
    }
    cout << endl;
}
