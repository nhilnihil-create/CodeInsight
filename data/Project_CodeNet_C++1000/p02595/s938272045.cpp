#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,d,sum=0;
	cin>>n>>d;
	double x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(sqrt(x*x+y*y)<=d*1.0)sum++;
	}
	cout<<sum;
	return 0;
}