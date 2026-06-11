#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M1,D1;
int main()
{
	cin>>M1>>D1;
	if(D1<10)cout<<0<<endl;
	else 
	{   int sum=0;
		for(int j=1;j<=M1;j++)
		for(int i=20;i<=D1;i++)
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