#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MIN -10000000
#define MAX 10000000

int main()
{
  int n,k,c;cin>>n>>k>>c;
  string s;cin>>s;
  vector<bool> can(n);
  int i;
  rep(i,s.size())
  {
    if(s[i]=='o')can[i]=true;
    else can[i]=false;
  }
  //front,back
  vector<int> dp1(k+1,0);
  dp1[0]=MIN;
  int now=0;
  rep(i,n)
  {
    if(!can[i])continue;
    else if(now<k&&dp1[now]<i-c)
    {
      dp1[now+1]=i;
      now++;
    }
  }
  vector<int> dp2(k+1,n);
  dp2[k]=MAX;
  now=k;
  for(i=n-1;i>=0;i--)
  {
    if(!can[i])continue;
    else if(now>0&&dp2[now]>i+c)
    {
      dp2[now-1]=i;
      now--;
    }
  }
  rep(i,k)
  {
    if(dp1[i+1]==dp2[i])
    {
      cout<<dp2[i]+1<<endl;
    }
  }
}
