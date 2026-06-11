#include<bits/stdc++.h>
using namespace std;
long long x,k,d;
int main(){
	cin>>x>>k>>d;
	if (x>0){
		if (x/d<=k)
			k-=x/d,x=x%d;
		else
			x-=k*d,k=0;
		if (k%2==0)
			cout<<x<<endl;
		else
			cout<<abs(x-d)<<endl;
	}
	else if (x<0){
		if ((-1*x)/d<=k)
			k-=(-1*x)/d,x=-1*((-1*x)%d);
		else
			x+=k*d,k=0;
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
