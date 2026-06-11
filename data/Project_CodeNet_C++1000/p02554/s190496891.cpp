#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod =1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	ll v1=1,v2=1,tot=1;
	
	for(int i=0;i<n;i++){
		tot=tot*10 %mod;

		v1=v1*9 %mod;
		v2=v2*8 %mod;
	}

	ll ans = (tot-2*v1+v2)%mod;
	if(ans<0)ans+=mod;

	cout<<ans<<'\n';
	return 0;
}