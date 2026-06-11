#include<iostream>
using namespace std;
int func(int count,int bused,int q,int sum){
	if(count==0){
		return sum==q?1:0;
	}
	int res = 0;
	for(int i=bused+1;i<=9;++i){
		res += func(count-1,i,q,sum+i);
	}
	return res;
}
bool func2(){
	int a,b;
	cin>>a>>b;
	if(a==0&&b==0){
		return false;
	}
	cout<<func(a,-1,b,0)<<endl;
	return true;
}
int main(){
	while(func2());
	return 0;
}
