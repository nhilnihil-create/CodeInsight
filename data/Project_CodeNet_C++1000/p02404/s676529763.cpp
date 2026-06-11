#include <iostream>
#include <iomanip>
#define pi 3.14159265358979323846
using namespace std;

int main()
{
	int H,W,i,j;
	while(true)
	{
		cin>>H>>W;
		if(H!=0||W!=0){
			
			for(i=1;i<=H;i++)
			{
				if(i==1||i==H)
					{
					for(j=1;j<=W;j++)
						{
							cout<<'#';
						}
					cout<<endl;
					} 
				else
				{
					cout<<'#';
					for(j=2;j<W;j++)
						cout<<'.';
					cout<<'#'<<endl;
				}
				
			}
		
		}
		else
			return 0; 
		cout<<endl;
	}
}
 
