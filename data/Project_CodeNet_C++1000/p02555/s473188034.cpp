#include<iostream>
#include<vector>
#define p 1000000007
using namespace std;

 long long int dp[2002][2002];
long long int h(vector<int> &v,int i,int m,int target)
{
  if(target==0)
	return 1;
  if(i>=m || target<3)
    return 0;
  if(dp[i][target]!=-1)
    return dp[i][target];
  long long int inc=h(v,0,m,target-v[i]);
  long long int exc=h(v,i+1,m,target);
  return dp[i][target]=((inc%p)+(exc%p))%p;
}
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  for(int i=3;i<=n;i++)
    v.push_back(i);
  for(int i=0;i<=2001;i++)
  {
    for(int j=0;j<=2001;j++)
      dp[i][j]=-1;
  }
  int m=v.size();
  cout<<h(v,0,m,n)<<endl;
  return 0;
}