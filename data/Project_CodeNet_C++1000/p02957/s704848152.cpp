#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    ll a,b;
    cin >> a >> b;
    if ((a+b)%2) cout << "IMPOSSIBLE" << endl;
    else cout << (a+b)/2 << endl;
    return 0;
}
