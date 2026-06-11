#include<bits/stdc++.h>
using namespace std;
int main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //cout<<;
  int a,b;
  cin>>a>>b;
  int count=0;
  for(int i=1;i<=a;i++)
  	{
  		for(int j=11;j<=b;j++)
  		{
  			if(j>99)
  			{
  				break;
  			}
  			int a=j%10;
  			int d=j/10;
  			int c=d%10;
  			if(a>=2 && c>=2)
  			{
  			if(a*c==i)
  			{
  				count++;
  			}
  		}
  			else
  			{
  				continue;
  			}
  		}
  	}
  	cout<<count<<endl;



}
