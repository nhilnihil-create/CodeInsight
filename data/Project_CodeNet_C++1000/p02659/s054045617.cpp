#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ll A;
    double B;
    cin >> A >> B;
    ll B2 = B*100 + 0.001;
    ll ans = A*B2;
    ans /= 100;
    cout << ans << endl;
}