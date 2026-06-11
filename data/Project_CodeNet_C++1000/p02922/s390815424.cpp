#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a,b;
	cin>>a>>b;
	cout<<ceil((b-a)/(a-1))+1<<"\n";
	return 0;
}