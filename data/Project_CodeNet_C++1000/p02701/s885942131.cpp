#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long int lli;
typedef long long ll;
#define mod 10000000007
int main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  lli n,i,k=0;
  cin>>n;
  map<string,int> mp;
  for(i=0;i<n;i++)
  {
      string s;
      cin>>s;
      mp[s]++;
  }
  for(auto it=mp.begin();it!=mp.end();it++)
  {
      k++;
  }
  cout<<k<<"\n";
}