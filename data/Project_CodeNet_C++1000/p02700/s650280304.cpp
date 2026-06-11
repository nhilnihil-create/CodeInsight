#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int TakAtt,AokiAtt;
	if(c%b!=0){
		TakAtt=c/b+1;
	}
	else{
		TakAtt=c/b;
	}
	if(a%d!=0){
		AokiAtt=a/d+1;
	}
	else{
		AokiAtt=a/d;
	}
	if(TakAtt>AokiAtt){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
	
}