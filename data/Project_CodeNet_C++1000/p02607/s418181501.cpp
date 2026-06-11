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
		int a[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if((i*i)%2!=0 && a[i]%2!=0)
				cnt++;
		}
		cout<<cnt<<"\n";
	}
}
