#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long double a,b,c;
	cin>>a>>b>>c;
	long double x=sqrt(a);
	long double y=sqrt(b);
	long double z=sqrt(c);
	long double eps = 1.0E-14;
	if(x+y+eps<z){
		cout<<"Yes"<<"\n";
	}else{
		cout<<"No"<<"\n";
	}

	
	
	
	
	return 0;
}