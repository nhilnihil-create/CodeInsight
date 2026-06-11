#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    
  string s;
  cin>>s;
  n=s.size();
  int yes=1;
  int l=0,r=n-1;
  while(l<r)
  {
   	if(s[l]!=s[r])
    {
     	yes=0; 
    }
    l++;
    r--;
  }
  l=0;
  r=(n-1)/2-1;
  while(l<r)
  {
   	if(s[l]!=s[r])
    {
     	yes=0; 
    }
    l++;
    r--;
  }
  l=(n+3)/2-1;
  r=(n-1);
while(l<r)
  {
   	if(s[l]!=s[r])
    {
     	yes=0; 
    }
    l++;
    r--;
  }
  if(yes==1)
  {
   cout<<"Yes"; 
  }
  else
  {
	cout<<"No";
  }
  
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