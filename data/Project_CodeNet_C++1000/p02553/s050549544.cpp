typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
ll maxl(ll a, ll b){ return ((a<b)?b:a);}
ll minl(ll a, ll b){ return ((a>b)?b:a);}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll val1 = a*c;
    ll val2 = a*d;
    ll val3 = b*c;
    ll val4 = b*d;
    ll ans = maxl(val1,maxl(val2,maxl(val3,val4)));
    cout << ans << "\n";
}

