#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;

int k,q,d[5010],num[5010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>k>>q;
	for(int i=0;i<k;i++) cin>>d[i];
	while(q--){
		int n,x,m;
		cin>>n>>x>>m;
		for(int i=0;i<k;i++){
			num[i]=(n-1ll)/k+(((n-1ll)%k)>i);
		}
		int equal=0ll,large=0ll;
		for(int i=0;i<k;i++){
			if(d[i]%m==0ll) equal+=num[i];
		}
		int val=x%m;
		for(int i=0;i<k;i++){
			val+=(d[i]%m)*num[i];
		}
		large=val/m;
		cout<<n-1ll-equal-large<<endl;
	} 
	return 0;
}