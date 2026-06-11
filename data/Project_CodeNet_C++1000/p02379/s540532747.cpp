#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	printf("%lf\n",sqrt((a-c)*(a-c)+(b-d)*(b-d)));
	return 0;
}