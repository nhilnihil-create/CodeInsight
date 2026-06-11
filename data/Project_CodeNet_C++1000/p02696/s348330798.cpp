#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, n; cin >> a >> b >> n;
    ll res = 0;
    
    if(n<b){
        ll x1 = (a*n/b); 
        ll x2 = n/b; x2 *= a;
        res = x1-x2;
        cout << res << endl;
    }
    else{
        n = b-1;
        ll x1 = (a*n/b); 
        ll x2 = n/b; x2 *= a;
        res = x1-x2;
        cout << res << endl;
    }
    return 0;
}