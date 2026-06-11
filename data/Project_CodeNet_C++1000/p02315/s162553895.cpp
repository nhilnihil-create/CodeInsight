#include <iostream>
using namespace std;
int main()
{
  int n,weight;
  cin>>n>>weight;
  int w[n+1]={0};
  int v[n+1]={0};
  for(int i=1;i<=n;i++)
  {
    cin>>v[i]>>w[i];
  }

  int value[n+1][weight+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=weight;j++)
      value[i][j]=0;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=weight;j++)
    {
      if(j-w[i]<0)
        value[i][j]=value[i-1][j];
      else
        if(value[i-1][j]<=v[i]+value[i-1][j-w[i]])
          value[i][j]=v[i]+value[i-1][j-w[i]];
        else
          value[i][j]=value[i-1][j];
    }
  }

  cout<<value[n][weight]<<endl;
  return 0;
}