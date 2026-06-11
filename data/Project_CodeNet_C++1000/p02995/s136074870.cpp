#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return a==0?b:gcd(b%a,a);}
ll a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    ll ans=b/c-a/c+b/d-a/d-(b/(c*d/gcd(c,d))-a/(c*d/gcd(c,d)));
    if(a%c==0)ans++;
    if(a%d==0)ans++;
    if(a%(c*d)==0)ans--;
    ans=b-a+1-ans;
    cout<<ans<<endl;
	return 0;
}