#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 1000000;

ll gcd(ll x, ll y){
    if(x<y){
        ll t = y;
        y = x;
        x = t;
    }
    if(x%y==0){return y;}
    else{return gcd(y, x%y);}
}

ll lcm(ll x, ll y){
    return (x*y)/gcd(x,y);
}

int main(){
    ll a, b; cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}