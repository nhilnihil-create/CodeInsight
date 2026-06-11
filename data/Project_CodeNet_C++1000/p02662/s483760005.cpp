#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,s;
  cin>>n>>s;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  int p=998244353;
  vector<vector<int>> c(s+1,vector<int>(n+1,0));
  c[0][0]=1;
  for(int i=0;i<=s;i++)
    for(int j=1;j<=n;j++)
      c[i][j]=(c[i][j-1]*2%p+(j>0&&a.at(j-1)<=i?c[i-a.at(j-1)][j-1]:0))%p;
  cout<<c[s][n]<<endl;
}