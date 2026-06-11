#include<bits/stdc++.h>
#define ll long long int 
using namespace std;



int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	int x,n;
   	cin>>n>>x;
   	int a[n];
   	for(int i=0;i<n;i++)
   	{
   		cin>>a[i];
   	}
   	int sum=0;
   	int i;
   	for(i=0;i<n;i++)
   	{
   		sum+=a[i];
   		if(sum>x)
   		{
   			break;
   		}
   	}
   	cout<<i+1<<endl;
	return 0;

}