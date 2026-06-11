#include <iostream>
using namespace std;

int main() 
{
	int h,a,t=0;
	cin>>h>>a;
	while(h>0)
	{
		h=h-a;
		t=t+1;
	}
	cout<<t;
	return 0;
}