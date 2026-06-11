#include <bits/stdc++.h> 
using namespace std; 
int main() 
{
	float s, a, b, c;
	cin>>s;
	a = s/3;
	s-=a;
	b = s/2;
	c = s-b;
	cout<<fixed<<setprecision(6)<<(a*b*c)<<endl;
	return 0;
}