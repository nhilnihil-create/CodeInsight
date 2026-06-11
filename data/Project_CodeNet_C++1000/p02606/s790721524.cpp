#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
	int t;
	t=1;
	while(t--)
	{
     int l,r,d;
     cin>>l>>r>>d;
     int count=0;
     for(int i=l;i<=r;i++)
     {
       if(i%d==0)
       {
       	count++;
       }
     }
     cout<<count;
	}
}