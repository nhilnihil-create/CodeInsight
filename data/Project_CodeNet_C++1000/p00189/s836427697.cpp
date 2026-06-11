#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
using namespace std;
main(){
  int m,n;
  while(cin>>n,n){
    int a[10][10],s[10],b,c,d;
    bool q[10];
    r(i,10){q[i]=0;s[i]=0;r(j,10){
      if(i==j)a[i][j]=0;
      else a[i][j]=INF;
    }}
    while(n--){
      scanf("%d%d%d",&b,&c,&d);
      a[c][b]=a[b][c]=d;
      q[c]=1;q[b]=1;
    }
    r(k,10)r(i,10)r(j,10){
      a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
    r(i,10)if(q[i])r(j,10){
      if(q[j]&&a[i][j]!=INF)s[i]+=a[i][j];
    }
    int p=0,ss=1<<29;
    r(i,10){
      if(q[i]&&ss>s[i]){
        ss=s[i];
        p=i;
      }
    }
    cout<<p<<' '<<ss<<endl;
  }
}