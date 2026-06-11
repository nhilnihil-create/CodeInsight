#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=13;
int NN_MAX=4096;
int INF=1e9;
int main()
{
  int n,m,a,b,t,i,j,k;
  int c[N_MAX],d[NN_MAX],s[NN_MAX][N_MAX],po[N_MAX];
  cin >> n >> m;
  po[0]=1;
  for(i=1;i<=n;i++)
    po[i]=po[i-1]*2;
  for(i=0;i<po[n];i++){
    t=i;
    for(j=0;j<n;j++){
      s[i][j]=t%2;
      t/=2;
    }
    d[i]=INF;
  }
  d[0]=0;
  for(k=0;k<m;k++){
    cin >> a >> b;
    for(i=0;i<b;i++){
      cin >> c[i];
      c[i]--;
    }
    for(i=0;i<po[n];i++){
      t=i;
      for(j=0;j<b;j++)
        if(s[i][c[j]]==0)
          t+=po[c[j]];
      d[t]=min(d[t],d[i]+a);
    }
  }
  if(d[po[n]-1]==INF)
    cout << "-1" << endl;
  else
    cout << d[po[n]-1] << endl;
  return 0;
}
