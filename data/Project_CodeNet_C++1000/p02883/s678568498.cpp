#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
long long k;
long long a[200010];
long long f[200010];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	sort(a,a+n);
	sort(f,f+n);
	ll l=0,r=2e18;
	while(l<r){
		ll mid=(l+r)/2;
		long long cnt=0;
		vector<ll> v;
		for(int i=0;i<n;i++){
			v.push_back(mid/f[i]);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			if(a[i]>v[i]){
				cnt+=(a[i]-v[i]);
			}
		}
		if(cnt<=k){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<r<<endl;
	return 0;
}