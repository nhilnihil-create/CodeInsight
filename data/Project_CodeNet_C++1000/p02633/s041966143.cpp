#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=179;i++)
	
	{
		if((i*360)%n==0)
		{
			cout<<(i*360)/n;
			break;
		}
	}
  return 0;
}