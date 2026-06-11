#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int a,b,c,mx;
int main(){
	cin>>a>>b>>c;
	mx=fmax(a,b);
	mx=fmax(mx,c);
	mx=a+b+c-mx;
	cout<<mx;
}