#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin >> a >> b >> c;
    if((4*a*b < (c-a-b)*(c-a-b)) && c>a+b) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}