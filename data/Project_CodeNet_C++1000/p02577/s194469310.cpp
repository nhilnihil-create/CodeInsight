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
     string s;
     cin>>s;
     k=0;
     for(i=0;i<s.size();i++)
     {
     	k+=(s[i]-'0');
     	k=k%9;
     }	
     if(!k)
    cout<<"Yes";
    else
    	cout<<"No";

	
	

}
//Lordvishnu@almighty