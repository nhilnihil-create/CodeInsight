#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fo1(i,n) for(int i=0;i<n;i++)
#define lli long long int
#define llu unsigned long long int
#define vi vector <int>
#define vii vector <long long int>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define mk make_pair
#define mpp map<int,int>
#define ff first
#define ss second
#define mod 1000000007

using namespace std;

int main()
{
	//fast;
    int t=1;
    //cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		int a[n+1]={0};
		for(int x=1;x<=100;x++)
		{
			for(int y=1;y<=100;y++)
			{
				for(int z=1;z<=100;z++)
				{
					int ans = x*x + y*y + z*z + x*y + y*z + z*x;
					if(ans <= n) 
						a[ans]++;
					else
						break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<"\n";
	}
} 