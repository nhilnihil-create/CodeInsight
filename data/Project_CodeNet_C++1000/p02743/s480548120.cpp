#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
long long a,b,c,x,y;
int main(){
	cin>>a>>b>>c;
	if(a+b>=c){
		cout<<"No";
		return 0;
	}
	x=4*a*b;
	y=(c-a-b)*(c-a-b);
	if(x<y)	cout<<"Yes";
	else cout<<"No";
 	return 0;
}