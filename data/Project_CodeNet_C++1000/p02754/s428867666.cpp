#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n,a,b;
    cin>>n>>a>>b;
    ll var1=n%(a+b);
    ll var2=n/(a+b);
    ll ans=var2*a + min(var1,a);  
	cout<<ans; 
	return 0;
}