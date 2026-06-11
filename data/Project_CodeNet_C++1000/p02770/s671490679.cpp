#include<bits/stdc++.h>
using namespace std;
int main(){
	long long k,q,i,j,n,x,m,a,A;cin>>k>>q;
  	int d[k];
	for(i=0;i<k;i++)cin>>d[i];
	for(i=0;i<q;i++){
		cin>>n>>x>>m;a=x%m;
		for(j=0;j<k;j++)a+=((d[j]+m-1)%m+1)*((n-2+k-j)/k);
		A=n-1-a/m;cout<<A<<endl;
	}
}