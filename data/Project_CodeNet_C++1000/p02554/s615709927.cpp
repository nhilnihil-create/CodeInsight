#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b=1,c=1,d=1;
	cin>>a;
	if(a==1){cout<<0;return 0;}
	for(int i=1;i<=a;i++){
		b*=10;
		c*=9;
		d*=8;
		b%=1000000007;
		c%=1000000007;
		d%=1000000007;
	}
	cout<<(b-c-c+d+1000000007+1000000007)%1000000007;
}