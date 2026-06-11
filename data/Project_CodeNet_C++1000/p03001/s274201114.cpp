#include <iostream>
using namespace std;

int main() {
	int w,h,x,y;
	cin>>w>>h>>x>>y;
	double m = w*1.0*h*1.0/2.0;
	bool mul = x+x==w && y+y==h;
	cout<<m<<" "<<(mul?'1':'0')<<endl; 
	return 0;
}