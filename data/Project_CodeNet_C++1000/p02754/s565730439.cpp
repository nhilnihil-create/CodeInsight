#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll x = n/(a+b);
    ll y = n-x*(a+b);
    if(y>a)y=a;

    ll ans = x*a+y;

    cout << ans << endl;
    return 0;
    
}