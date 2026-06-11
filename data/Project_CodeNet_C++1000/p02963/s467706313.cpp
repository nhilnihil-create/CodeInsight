#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s;
    cin >> s;
    ll n=s;
    ll d=2;
    ll yb=1000000000;
    ll xa=(s+yb-1)/yb;
    ll ya=xa*yb-s;
    ll xb=1;
    cout << xa << " " << ya << " " << xb << " " << yb << " 0 0" << "\n";

    return 0;
}