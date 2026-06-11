#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (b-b/c-b/d+b/(c*d/__gcd(c,d))) - ((a-1)-(a-1)/c-(a-1)/d+(a-1)/(c*d/__gcd(c,d))) << endl;
    return 0;
}