#include <iostream>
using namespace std;
int main()
{
	int k;
	cin>>k;
	string str="ACL";
	
	
	for (int i=1; i<k; i++)
	{
		str=str+"ACL";
	}
	cout<<str<<endl;
	
	return 0;
}