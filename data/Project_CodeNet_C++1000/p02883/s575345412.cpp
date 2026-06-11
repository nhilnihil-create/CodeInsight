#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514],f[214514];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>f[i];
	ll ma=0;
	sort(a,a+n);
	sort(f,f+n);
	for(int i=0;i<n;i++)ma=max(ma,a[i]*f[n-i-1]);
	//cout<<ma<<endl;
	ll ok=ma,ng=-1;
	while(ok-ng>1){
		ll mid=(ok+ng)/2;
		//cout<<mid<<endl;
		ll x=k;
		bool yan=0;
		for(int i=0;i<n;i++){
			if(a[i]*f[n-i-1]>mid){
				ll num=mid/f[n-i-1];
				x-=a[i]-num;
			}
			if(x<0){
				yan=1;
				break;
			}
		}
		if(yan)ng=mid;
		else ok=mid;
	}
	cout<<ok<<endl;
	return 0;
}
