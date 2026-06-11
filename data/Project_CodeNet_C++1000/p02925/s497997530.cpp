#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=1000;
int main()
{
  int n,t,i,j,res;
  bool fb,fe,f[N_MAX];
  int a[N_MAX][N_MAX],p[N_MAX];
  cin >> n;
  for(i=0;i<n;i++)
    for(j=0;j<n-1;j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  fill(p,p+n,0);
  for(res=0;;res++){
    fb=0;
    fe=1;
    fill(f,f+n,0);
    for(i=0;i<n;i++){
      if(f[i]==1||p[i]==n-1)
        continue;
      fe=0;
      t=a[i][p[i]];
      if(f[t]==0&&a[t][p[t]]==i){
        f[i]=1;
        f[t]=1;
        p[i]++;
        p[t]++;
        fb=1;
      }
    }
    if(fe==1){
      cout << res << endl;
      return 0;
    }
    if(fb==0){
      cout << "-1" << endl;
      return 0;
    }
  }
  return 0;
}