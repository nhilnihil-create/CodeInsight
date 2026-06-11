#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e6+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=1000001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
//Lordvishnu@almighty
int main()
{
	
	ll int i,j,k,n,m;
	cin>>n;
     ll a[n];
     for(i=0;i<n;i++)
     	cin>>a[i];
    ll  l=a[0];
     m=0;
     for(i=1;i<n;i++)
     {
     	m+=max(0ll,l-a[i]);
     	l=max(l,a[i]);
     }
     cout<<m;
	
	

}
//Lordvishnu@almighty