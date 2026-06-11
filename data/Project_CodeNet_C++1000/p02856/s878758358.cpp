#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,last=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x,y,sum;
		cin>>x>>y;
		num+=y;
		sum=x*y+last;
		while(sum>=10){
			num+=sum/10;
			sum=sum/10+sum%10;
		}
		last=sum;
	}
	cout<<num-1<<endl;
}