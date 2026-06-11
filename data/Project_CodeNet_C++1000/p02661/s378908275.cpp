#include<bits/stdc++.h>
using namespace std;
double mi[200001],ma[200001];
int main(){
	int n,i;
	cin>>n;
	for(i=1;i<=n;++i)cin>>mi[i]>>ma[i];
	sort(mi+1,mi+n+1);
	sort(ma+1,ma+n+1);
	if(n&1){
		int a=mi[n+1>>1],b=ma[n+1>>1];
		cout<<b-a+1;
	}else{
		double a=(mi[n>>1]+mi[n+2>>1])/2.0,b=(ma[n>>1]+ma[n+2>>1])/2.0;
		int c=(b-a)*2+1;
		cout<<c;
	}
} 