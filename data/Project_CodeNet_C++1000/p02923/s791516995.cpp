#include<bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pii pair <int,int>
#define vi vector <int>
#define vvi vector <vector <int> >
#define vpii vector <pair <int,int> >
#define ll long long
#define ld long double
#define rep(x,a,b) for(x=a;x<b;x++)
#define db double
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
#define mii map <int,int>
#define mod 1000000007


int main()
{
	IOS
	
	int n,i,j;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	int ans=0;
	for(i=0;i<n;)
	{
		j=i;
		while(j<n-1 && a[j]>=a[j+1])
		j++;
		
		
		ans=max(ans,j-i);
		i=j+1;
	}
	
	cout<<ans;
}