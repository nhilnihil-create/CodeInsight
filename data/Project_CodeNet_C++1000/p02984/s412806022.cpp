#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;

long long n,a[M],tot=0,tot2=0,x[M];

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]*=2;
		tot+=a[i];
	}
	tot2=tot/2;
	for (int i=1;i<n;i+=2){
		tot2-=a[i];
	}
	//now, tot2=Xn
	x[n]=tot2;
	x[1]=a[n]-x[n];
	for (int i=1;i<n;i++){
		x[i+1]=a[i]-x[i];
	}
	for (int i=1;i<=n;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
