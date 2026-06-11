#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

main() {
	int n, k;
	cin>>n>>k;
	vector<int>a;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	vector<int>f;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		f.pb(x);
	}
	sort(a.begin(), a.end());
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	int hi=1e13;
	int lo=0;
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		int num=0;
		for(int i=0; i<n; i++){
			int shou=(mid)/f[i];
			if(shou>=a[i]){
				continue;
			}
			num+=(a[i]-shou);
		}
		if(num<=k){
			hi=mid-1;
			ans=mid;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	return 0;
}