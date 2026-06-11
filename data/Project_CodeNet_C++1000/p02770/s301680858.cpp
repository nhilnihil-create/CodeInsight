#include <iostream>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
main(){
	long k,q,n,x,m,a;cin>>k>>q;
  	int d[k];
	r(i,k)cin>>d[i];
	r(i,q){
		cin>>n>>x>>m;a=x%m;
		r(j,k)a+=((d[j]+m-1)%m+1)*((n-2+k-j)/k);
		cout<<n-1-a/m<<endl;
	}
}
