#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=2001;
int p=1e9+7;
int main()
{
  int n,m,i,j;
  int s[N_MAX],t[N_MAX],u[N_MAX][N_MAX];
  cin >> n >> m;
  for(i=0;i<n;i++){
    cin >> s[i];
    u[i+1][0]=1;
  }
  fill(u[0],u[0]+m+1,1);
  for(j=0;j<m;j++)
    cin >> t[j];
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(s[i-1]==t[j-1]){
        u[i][j]=(u[i-1][j]+u[i][j-1])%p;
      }else{
        u[i][j]=(u[i-1][j]+u[i][j-1]-u[i-1][j-1])%p;
        if(u[i][j]<0)
          u[i][j]+=p;
      }
  cout << u[n][m] << endl;
  return 0;
}
