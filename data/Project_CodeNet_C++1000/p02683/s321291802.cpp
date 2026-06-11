#include<bits/stdc++.h>
using namespace std;
int main()
{
long int n,m,i,j,k,min,x,temp,sw;
  temp=0;
  sw=0;
  min=20000000;
  cin >> n >> m >> x; 
long int c[n],a[n][m],sum[m];
  
  for(i=0;i<n;++i)
  {
  cin >> c[i];
   for(j=0;j<m;j++)
   {
   cin >> a[i][j];
   }
  }
  
  for(j=0;j<m;j++)
  {sum[j]=0;
   }
  
  
  for(i=0;i<(1<<12);++i)
  {
  bitset<12> s(i);
    for(j=0;j<n;++j)
    {
    if(s.test(j)) {temp=temp+c[j];
      for(k=0;k<m;++k)
      {
      sum[k]=sum[k]+a[j][k];
      }
     }
    }
    for(k=0;k<m;++k)
      {
      if(sum[k]>=x) sw++;
      sum[k]=0;
      }
    if(sw==m && temp < min) min=temp;
    sw=0;
    temp=0;
  }
  if(min==20000000) cout << "-1";
  else cout << min;

return 0;}