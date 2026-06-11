#include <iostream>
using namespace std;
int main()
{
	int d, r;
	while (1)
	{
		cin>>d>>r;
		if (d ==0 && r == 0)
			break;
		else
		{
			for (int i =0; i < d;i++)
			{
				for (int j=0;j <r;j++)
				{
					if (i == 0 || i == d -1 || j == 0 || j == r - 1)
						cout<<"#";
					else
						cout<<".";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}