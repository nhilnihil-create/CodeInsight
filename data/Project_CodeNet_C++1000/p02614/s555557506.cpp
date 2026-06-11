#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int col[10][10];

int main(void)
{
  // freopen("aaa.in","r",stdin);
  int H,W,K;
  scanf("%d%d%d",&H,&W,&K);
  char s[10];
  for (int i=1;i<=H;i++)
  
  {
    scanf("%s",s);
    for (int j=0;j<W;j++)
    if (s[j]=='.') col[i][j+1] = 0;
    else col[i][j+1] = 1;
  }
  // cout<<col[1][2]<<" "<<col[2][2]<<endl;
  int ans = 0;
  int a[10],b[10];

  for (int i=0;i<(1<<H);i++)
  for (int j=0;j<(1<<W);j++)
  {
      int cnta = 0,cntb = 0;
      for (int k=0;k<H;k++)
      if (((1<<k)&i)==0) a[++cnta] = k+1;
      
      for (int k=0;k<W;k++)
      if (((1<<k)&j)==0) b[++cntb] = k+1;

      int tmp = 0;
      for (int ki=1;ki<=cnta;ki++)
      for (int kj=1;kj<=cntb;kj++)
      tmp+=col[a[ki]][b[kj]];

      if (tmp==K) 
      {
        ans++;
        // cout<<i<<" "<<j<<endl;
        // for (int ki=1;ki<=cnta;ki++)
        // for (int kj=1;kj<=cntb;kj++)
        // cout<<a[ki]<<" "<<b[kj]<<endl;
        // cout<<"---------"<<endl;
      }  
  }
  printf("%d\n",ans);
  return 0;
}