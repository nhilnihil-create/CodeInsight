#include <bits/stdc++.h>
#include<set>
#include <algorithm>
#define ll long long 
#include <string.h>
#define pb push_back
#define mp make_pair
# define pi 3.14159265358979323846
using namespace std;
int main()
{
	ll int h,w,k;
	cin>>h>>w>>k;
	char s[h][w];
	ll int ans=0;
	
	ll int i,j;
	for(i=0;i<h;i++)
	{
	for(j=0;j<w;j++)
	{
		cin>>s[i][j];
		
	}
	}
	ll int l,m;
	ll int c=0;
	for(i=0;i<1<<h;i++)
	{
		for(j=0;j<1<<w;j++)
		{
			c=0;
			for(l=0;l<h;l++)
			{
				for(m=0;m<w;m++)
				{
					if (((i>>l)&1)||(((j>>m)&1)))
					continue;
					
				    if (s[l][m]=='#')
					c++;
				}
			}
			
			if (c==k)
			ans++;
		}
	}
	cout<<ans<<endl;
	
	
}

    
	
		

	
			

		


 




