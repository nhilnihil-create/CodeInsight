#include <iostream>
using namespace std;

int gcd(int x,int y);

int main() {
	int a,b;
	int x,y;
	cin>>a>>b;
	x=min(a,b);
	y=max(a,b);
	gcd(x,y);
	return 0;
}

int gcd(int x,int y){
	if(y%x!=0)gcd(y%x,x);
	else cout<<x<<endl;
}