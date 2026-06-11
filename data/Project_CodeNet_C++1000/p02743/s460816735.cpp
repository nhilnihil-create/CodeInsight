#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    bool possible = true;
    if (a + b >= c) possible = false;
    else{
        ll x = 4 * a * b;
        ll y = (c - a - b) * (c - a - b);
        if (x >= y) possible = false;
    }
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}