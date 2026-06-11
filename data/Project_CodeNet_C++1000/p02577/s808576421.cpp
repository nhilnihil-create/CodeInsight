#include<iostream>
using namespace std;
int main(){
	char a;int b,sum=0;
	while(1){
		a=cin.get();
		b=(int)a-48;
		if(b>=10||b<0)break;
		sum+=b;
		
	}
	if(sum%9==0)cout<<"Yes";
	else cout<<"No";
	return 0;
}