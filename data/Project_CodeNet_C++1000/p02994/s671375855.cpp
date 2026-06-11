//B Ed 31
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int n,l,x=0,y,in;cin>>n>>l;
	int a[n];
	int index = 0;
	for(int i=0;i<n;i++)
		{
			y=(l+i+1)-1;
			a[i]=abs((l+i+1)-1);
			x=x+y;
		}
	for(int i = 0; i <n; i++)
    {
        
        if(a[i] < a[index])
            index = i;              
    }
 
  cout<<x-((l+index+1)-1);
}