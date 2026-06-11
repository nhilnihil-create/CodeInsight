#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a%b==0){return b;}
    else{return gcd(b, a%b);}
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll nc, nd, ncd;
    nc = b/c - a/c;
    if(a%c==0){nc += 1;}
    nd = b/d - a/d;
    if(a%d==0){nd += 1;}
    ll cd = lcm(c, d);
    ncd = b/cd - a/cd; 
    if(a%cd==0){ncd += 1;}
    ll res = (b-a+1)-(nc+nd-ncd);
    cout << res << endl;
    return 0;
}