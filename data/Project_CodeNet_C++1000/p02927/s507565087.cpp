#include<bits/stdc++.h>
using namespace std;
int M,D;
int main()
{
	cin>>M>>D;
	if(D<10)cout<<0<<endl;
	else 
	{   int sum=0;
		for(int j=1;j<=M;j++)
		for(int i=20;i<=D;i++)
		{ //cout<<1;
		if(i%10>=2){
		
		  if((i%10)*(i/10)==j)
		  {sum++;
		   //cout<<j<<" "<<i<<endl;
          }		
		}}
		 cout<<sum<<endl;
	}
}