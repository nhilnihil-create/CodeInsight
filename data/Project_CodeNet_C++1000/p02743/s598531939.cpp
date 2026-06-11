#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    bool ok = false;
    
    if((ll)4*a*b < (ll)a*a + b*b + c*c + 2*a*b -(2*b*c) - (2*a*c) && c-a-b > 0) ok = true;
    if (ok) cout << "Yes" <<endl;
    else cout << "No" << endl;
}