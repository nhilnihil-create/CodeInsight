#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	char op;
	int a,b,i,r,o,s,t;
	for(i=0;i<=20000;i++){
		cin>>a>>op>>b;
		if(op=='?'){
			break;
		}
		if(op=='+'){
			cout<<a+b<<endl;
		}else if(op=='-'){
			cout<<a-b<<endl;
		}else if(op=='*'){
			cout<<a*b<<endl;
		}else if(op=='/'){
			cout<<a/b<<endl;
		}
	}
}