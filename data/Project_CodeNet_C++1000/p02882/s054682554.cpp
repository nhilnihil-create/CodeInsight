#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,x;
	cin>>a>>b>>x;
	long double A=a,B=b,X=x,pie=3.1415926535897932384626;
	long double num;
	if(a*a*b<=2*x){
		num=atan(2.0*(A*A*B-X)/(A*A*A));

	}else{
		num=atan(A*B*B/(2.0*X));
	}
	num*=180.0/pie;
	cout<<fixed<<setprecision(20)<<num;
	return 0;
}
