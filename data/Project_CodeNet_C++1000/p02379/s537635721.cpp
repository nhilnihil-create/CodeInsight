#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	double x1,x2,y1,y2,s;
	
	cin>>x1>>y1>>x2>>y2;
	
	s=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	s=sqrt(s);
	
	printf("%lf",s);
}
