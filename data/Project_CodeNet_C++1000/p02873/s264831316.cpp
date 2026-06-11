#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main(){
  string s;
  cin>>s;
  int n=s.size();
  ll arr[n+1]={0};
  for(int i=0;i<n;i++)
  {
    if(s[i]=='<')
    {
      arr[i+1]=arr[i]+1;
    }
  }
  for(int i=n-1;i>=0;i--)
  {
    if(s[i]=='>')
    {
      arr[i]=max(arr[i+1]+1,arr[i]);
    }
  }
  ll ans=0;
  for(int i=0;i<n+1;i++)
  {
    ans+=arr[i];
  }
  cout<<ans<<endl;
}
