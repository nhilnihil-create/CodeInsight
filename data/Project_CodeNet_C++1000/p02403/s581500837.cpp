#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;
int main()
{
	
	int H[1000],W[1000],c[1000],d=1000,i;
	for( i=0;i<d;i++)
	{
		
	cin>>H[i]>>W[i];
	if(H[i]==0||W[i]==0)
		break;
	c[i]=H[i]*W[i];
	}
	for(int k=0;k<i;k++)
	{
		for(int j=1;j<=c[k];j++)
		{
			cout<<"#";
			if(j%W[k]==0)
				cout<<endl;
			
		}
		cout<<endl;
	
	
	}




	
}