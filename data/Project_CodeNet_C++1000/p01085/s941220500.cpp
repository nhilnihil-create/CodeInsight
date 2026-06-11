#include<bits/stdc++.h>
#define M 205
using namespace std;

int main(){
  while(1){
    int m,nmin,nmax,g=-1,ans,p[M];
    cin>>m>>nmin>>nmax;
    if(!m&&!nmin&&!nmax)break;
    for(int i=1;i<=m;i++)cin>>p[i];
    for(int n=nmin;n<=nmax;n++){
      if(p[n]==p[n+1])continue;
      if(g<=p[n]-p[n+1]){
	g=p[n]-p[n+1];
	ans=n;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}