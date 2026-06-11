#include<bits/stdc++.h>
using namespace std;

double distance(vector<int> y,vector<int> z)
{
  int sum=0;
  for(int i=0;i<(int)y.size();i++)sum+=(y[i]-z[i])*(y[i]-z[i]);
  return (double)pow(sum,0.5);
}

int main()
{
  int N,D,ans=0;scanf("%d %d",&N,&D);
  vector<vector<int>> X(N,vector<int>(D,0));
  for(int i=0;i<N;i++)for(int j=0;j<D;j++)scanf("%d ",&X[i][j]);
  for(int i=0;i<N;i++)for(int j=i;j<N;j++)
  {
    if(i==j)continue;
    if(distance(X[i],X[j])-(int)distance(X[i],X[j])==0)ans++;
  }
  printf("%d",ans);
}