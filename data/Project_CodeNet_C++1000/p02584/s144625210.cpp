#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	long long x,k,d,s;
	cin>>x>>k>>d;
	x=abs(x);
	s=min(k,x/d);
	if((k-s)%2==0){
		cout<<x-s*d<<endl;
	}else{
		cout<<(1+s)*d-x<<endl;
	}
}