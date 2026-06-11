#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	long double a,b,x;
	cin>>a>>b>>x;
	if(x*2>=a*a*b){
		long double ta=a*a*b-x;
		//cout <<ta<<endl;
		ta/=(a*a*a/2);
		//cout <<ta<<endl;
		printf("%.9Lf",atan(ta)*180.0/M_PI);
		return 0;
	}
	else{
		long double ta=x;
		ta/=(a*b*b/2);
		printf("%.9Lf",90.0-atan(ta)*180.0/M_PI);
	}
	// your code goes here
	return 0;
}