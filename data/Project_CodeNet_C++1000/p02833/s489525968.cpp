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
		if(n&1) cout<<"0"<<endl;
		else{
			ll ans=0,c=10;
			while(c<=n)
			{
				 ans=ans+(n/c);
				 c=c*5;
			}
			cout<<ans<<endl;
		}
	return 0;
}