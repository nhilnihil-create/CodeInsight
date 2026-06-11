#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll cnt[100005],upper[100005],a[100005];
int n;
bool f=1;


int main() {
	cin>>n;
	for(int i=0;i<=n;i++) {
		cin>>a[i];
	}
	upper[n]=0;
	for(int i=n-1;i>=0;i--) {
		upper[i]=upper[i+1]+a[i+1];
	}
	cnt[0]=1-a[0];
	ll ans=1;
	if(cnt[0]>upper[0] || a[0]>1) {
		f=0;
	}
	for(int i=1;i<=n;i++) {
		if(2*cnt[i-1]<a[i]) {
			f=0;
			break;
		}
		cnt[i]=min(upper[i],2*cnt[i-1]-a[i]);
		ans+=cnt[i]+a[i];
	}
	if(!f) {
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}