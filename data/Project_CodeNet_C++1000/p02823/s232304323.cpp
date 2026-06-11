#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pii pair<int,int> 
const int N=1e6+10;
const int mod=1e9+7;
using namespace std;

void solve(){
    ll n,a,b; cin>>n>>a>>b;
    if(abs(b-a)%2==0) {printf("%lld\n",abs(b-a)/2); return;}
    if(a>b) swap(a,b);
    ll ans=min(b-1, n-a);
    ll an=min(a-1+(b-a+1+1)/2,n-b+(n-(a+n-b)+1)/2);
    printf("%lld\n",min(an,ans)); 
}
int main() 
{
    int _=1;  //scanf("%d",&_);
    while(_--) solve();
    return 0;
}
/*
*/
 