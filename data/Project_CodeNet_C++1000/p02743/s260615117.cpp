#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll a,b, c;
    cin >> a >> b >> c;
    ll d = a+b-c;
    if ((d*d > 4*a*b && d < 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}