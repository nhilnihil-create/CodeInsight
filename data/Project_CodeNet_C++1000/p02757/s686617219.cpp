#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
string s;
ll n,p;
ll cnt[N];
int main() {
	ll i,sum=0,c=1,ans=0;
	cin>>n>>p>>s;
	if (p==2||p==5) {
		for (i=n-1;i>=0;i--)
			if ((s[i]-'0')%p==0) ans+=i+1;
		cout<<ans<<endl;
		return 0;
	}
//	for (i=0;i<p;i++) cnt[i]=1;
	cnt[0]=1;
	for (i=n-1;i>=0;i--) {
		sum=(sum+(s[i]-'0')*c)%p;
		cnt[sum]++;
		c=(c*10)%p;
	}
	ans=0;
	for (i=0;i<p;i++)
		ans+=cnt[i]*(cnt[i]-1)/2;
	cout<<ans<<endl;
	return 0;
}