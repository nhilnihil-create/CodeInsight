#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int f(int a[][18],int x,int y,int m,int n){
  int sm=0;
  if(a[x][y])
    return 0;
  if(x==m&&y==n)
    return 1;
  sm+=f(a,x+1,y,m,n);
  sm+=f(a,x,y+1,m,n);
  return sm;
}
int main(){
  int i,j;
  int a[18][18],m,n,o,p,q;
  memset(a,1,sizeof(a));
  while(cin>>m>>n&&m+n){
    cin>>o;
    for(i=1;i<n+1;i++)
      for(j=1;j<m+1;j++)
	a[j][i]=0;
    for(i=0;i<o;i++){
      cin>>p>>q;
      a[p][q]=1;
    }
    cout<<f(a,1,1,m,n)<<endl;
  }
  return 0;
}