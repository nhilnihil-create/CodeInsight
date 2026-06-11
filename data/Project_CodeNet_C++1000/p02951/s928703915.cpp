#include <iostream>
using namespace std;

int main()
{
  	int a, b, c, x, y, yu;
    cin>>a>>b>>c;
  	x=b;
    y=c;
  	yu=a-b;
  	y=y-yu;
	if(y<0)
    	cout<<0;
  	else
  		cout<<y;
	return 0;
}