#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll calc(ll x) {
   ll ans=1,cnt;
   for (ll i=2;i*i<=x;i++)
        if (x%i==0) {
        	cnt=0;
            while (x%i==0) x/=i,cnt++;
            ans=ans*(cnt+1);
        }
    if (x>1) ans=ans*2;
    return ans;
}
int main() {
	ll ans,i,m,p;
	cin>>n; m=n;
	if (n==2) {
		cout<<1<<endl;
		return 0;
	}
	ans=calc(n-1); p=0;
	for (i=2;i*i<=n;i++) if ((n-1)%i) {
		m=n;
		while (m%i==0) m/=i;
		if (m%i==1) ans++;		
	}
	cout<<ans<<endl;
	return 0;
}