#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	double a,b,x;
	cin>>a>>b>>x;
	if(2*x>=a*a*b){
		printf("%.9f",180*atan2((a*a*b-x)*2/(a*a*a),1.0)/M_PI);
	}
	else{
		printf("%.9f",90.0-180*atan2(2*x/(a*b*b),1.0)/M_PI);
	}
	// your code goes here
	return 0;
}