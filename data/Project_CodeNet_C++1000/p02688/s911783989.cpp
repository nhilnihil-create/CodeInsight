#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
  cin>>n>>k;
  int vis[n]={0};
  for(i=0;i<k;i++)
  {
   cin>>j;
    for(int x=0;x<j;x++)
    {
     	int p;
      	cin>>p;
      	vis[p-1]++;
    }
  }
  ll c=0;
  for(i=0;i<n;i++)
  {
    if(vis[i]==0)
	c++;
  }	
  cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}