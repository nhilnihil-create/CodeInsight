#include <iostream>
using namespace std;

int main()
{
	char a;
	int s=0;
	while((a=getchar())!='\n')
	{
		s+=(a-'0');
	}
    if(s%9==0)
    {
    	cout << "Yes" ;
	}
	else if(s%9!=0)
	{
		cout << "No";
	}
	cout << endl;
	return 0;
}