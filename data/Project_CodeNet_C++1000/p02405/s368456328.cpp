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
					if (i % 2 == 0)
					{
						if ( j % 2 == 0)
							cout<<"#";
						else
							cout<<".";
					}
					else
					{
						if ( j % 2 == 0)
							cout<<".";
						else
							cout<<"#";
					}

				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}