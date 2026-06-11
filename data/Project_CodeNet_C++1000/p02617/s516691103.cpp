#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define LIM 100005
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector <int>
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(), x.end()


int32_t main()
{
  IOS;
  int tt,x,y,k,q,n,i,j;
  cin>>n;
  int add=0,minus=0;
  for(i=1;i<=n;i++){
    add+= i*(n-i+1);
  }
  for(i=0;i<n-1;i++)
  {
    cin>>x>>y;
    if(x>y)swap(x,y);
    minus+= x*(n-y+1);
  }
  cout<<add-minus;
}
