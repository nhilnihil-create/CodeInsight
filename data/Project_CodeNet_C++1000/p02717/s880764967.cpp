#include<iostream>
using namespace std;

int main(){
	
	int a,b,c;
	cin>>a>>b>>c;
	int preva=a;
	int prevb=b;
	int prevc=c;
	a=prevc;
	b=preva;
	c=prevb;
	cout<<a<<" "<<b<<" "<<c<<endl;
	
}