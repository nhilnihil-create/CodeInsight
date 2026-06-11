#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll cn,dn,cdn;
    cn = b/c - (a-1)/c;
    dn = b/d - (a-1)/d;
    cdn = b/lcm(c,d) - (a-1)/lcm(c,d);
    ll ans = b-a+1-(cn+dn-cdn);
    cout << ans << endl;
    return 0;
}