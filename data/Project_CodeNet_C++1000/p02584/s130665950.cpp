#include<bits/stdc++.h>
using namespace std;
long long x,k,d;
int main(){
	cin>>x>>k>>d;
	if (x>0){
		if (x/d<=k)
			k-=x/d,x=x%d;
		else{
			while (k/100000000!=0){
				k-=100000000;
				x-=d*100000000;
			}
			while (k/1000!=0){
				k-=1000;
				x-=d*1000;
			}
			while (k!=0){
				k-=1;
				x-=d;
			}
		}
		if (k%2==0)
			cout<<x<<endl;
		else
			cout<<abs(x-d)<<endl;
	}
	else if (x<0){
		if ((-1*x)/d<=k)
			k-=(-1*x)/d,x=-1*((-1*x)%d);
		else{
			while (k/100000000!=0){
				k-=100000000;
				x+=d*100000000;
			}
			while (k/1000!=0){
				k-=1000;
				x+=d*1000;
			}
			while (k!=0){
				k-=1;
				x+=d;
			}
		}
		if (k%2==0)
			cout<<abs(x)<<endl;
		else
			cout<<abs(x+d)<<endl;
	}
	else{
		if (k%2==0)
			cout<<0<<endl;
		else
			cout<<abs(d)<<endl;
	}
	return 0;
}
