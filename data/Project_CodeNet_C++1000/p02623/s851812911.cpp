#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,m,k,prefa[200050],prefb[200050];
	cin >> n >> m >> k;
	prefa[0]=0;
	for(int i=1; i<=n; i++){
		ll x;
		cin >> x;
		prefa[i]=prefa[i-1]+x;
	}
	prefb[0]=0;
	for(int i=1; i<=m; i++){
		ll x;
		cin >> x;
		prefb[i]=prefb[i-1]+x;
	}
	ll jwb=0;
	for(int i=0; i<=n; i++){
		if(prefa[i]>k)break;
		ll sisa=k-prefa[i];
		ll l=0,r=m,mid,ans=0;
		while(l<=r){
			mid=(l+r)/2;
			if(prefb[mid]<=sisa){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		jwb=max(jwb,i+ans);
	}
	cout << jwb << endl;
}