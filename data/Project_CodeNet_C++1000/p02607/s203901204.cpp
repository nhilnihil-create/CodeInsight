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
     int n;

     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
     	cin>>arr[i];
     }
     int count=0;
     for(int i=0;i<n;i++)
     {
       if((i+1)%2==1&&arr[i]%2==1)
       {
       	count++;
       }
     }
     cout<<count;
	}
}