#include<iostream>
#include<algorithm>
using namespace std;
 
int i,j,k,h,w,ii,jj,cnt=0,ans=0;
int a[6],b[6];
char c[6][6];
 bool f=0;
 
int main (void)
{
 
  cin>>h>>w>>k;
  for(i=0;i<h;i++)for(j=0;j<w;j++)cin>>c[i][j];
  int n=1;
  for(i=0;i<h+w;i++){n*=2;}
  for(i=0;i<n;i++)
  {
    int aa=i;
    for(j=0;j<h+w;j++)
    {
      if(j<h){a[j]=aa%2;}
      else{b[j-h]=aa%2;}
      aa/=2;
    }
    for(ii=0;ii<h;ii++)
    {
      for(jj=0;jj<w;jj++)
      {
      if(a[ii]==0&&b[jj]==0&&c[ii][jj]=='#'){cnt++;}
      }
    }
    if(cnt==k)ans++;
    cnt=0;
  }
 
  cout<<ans<<endl;
  return 0;
}