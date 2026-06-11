#include<iostream>
#include<string>
using namespace std;
int main(){
	int a=0;
	int b=0;
	string t;
	int i=0;
	int d[10000];
	int x=0;
	while(1){
		cin>>a>>t>>b;
		if(t=="?"){
			break;
		}
		if(t=="+"){
			d[i]=a+b;
		}
		if(t=="-"){
			d[i]=a-b;
		}
		if(t=="*"){
			d[i]=a*b;
		}
		if(t=="/"){
			d[i]=a/b;
		}
		i++;
	}
	for(x=0;x<i;x++){
		cout<<d[x]<<endl;
	}
}