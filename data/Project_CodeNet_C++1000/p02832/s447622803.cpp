#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define sec second 
int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n; cin>>n;
	ll a[n],f=0;
	for(ll i=0;i<n;i++) { cin>>a[i]; if(a[i]==1) f=1;}
	if(f){
	ll c=1,ans=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]==c) c++;
		else ans++;
	}
	cout<<ans<<endl;
	}
	else cout<<"-1"<<endl;
	return 0;
}