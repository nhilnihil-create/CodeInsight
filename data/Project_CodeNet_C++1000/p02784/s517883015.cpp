#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>c;
		a-=c;
		if(a<=0){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
} 