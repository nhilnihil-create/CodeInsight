#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n,m;
    std::cout.precision(10);
    int yes=0;
  	cin>>n>>m;
  	while(m--)
    {
      cin>>i;
      n-=i;
    }
  if(n<0)
  {
   	cout<<"-1"; 
  }
  else
    cout<<n;
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