#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  	ll n,cnt=0,ans=0; cin>>n;
	char a[200005];
	for (ll i=1;i<=n;i++)  cin>>a[i];
	for (ll i=1;i<=n;i++){
		if (a[i]=='W')  cnt++;
	}
	for (ll i=n-cnt+1;i<=n;i++){
		if (a[i]!='W')  ans++;
	}
	cout<<ans<<endl;
	return 0;
}