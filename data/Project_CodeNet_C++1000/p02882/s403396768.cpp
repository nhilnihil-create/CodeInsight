#include<bits/stdc++.h>
using namespace std;
long double PI=acos(-1.0);
int main(){
	int a,b,x; cin>>a>>b>>x;
	long double y=(x/(long double)a);
	long double z=(0.5*(long double)a*b); 
	if(y<z){
	 long double f=atan2(b,(2*x)/(long double)(a*b)); 
	 long double ans = (f*180)/PI;
	 cout<<fixed<<setprecision(10)<<ans<<"\n"; 
	 }
	else{
	long double f=(2*x-(a*a*b));
	f/=(a*a);
	f=b-f; 
	f=atan2(f,a); 
	long double ans=(f*180)/PI; 
	cout<<fixed<<setprecision(10)<<ans<<"\n"; 
	 }
	 return 0;
	 }