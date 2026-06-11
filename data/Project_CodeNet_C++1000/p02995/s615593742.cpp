#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    ans=(b-a+1)-(b/c-(a-1)/c)-(b/d-(a-1)/d)+(b/((c*d)/__gcd(c,d))-(a-1)/((c*d)/__gcd(c,d)));
    cout<<ans;
}
