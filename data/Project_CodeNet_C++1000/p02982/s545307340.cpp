#include<bits/stdc++.h>
using namespace std;
int main()
{int m,n;
cin>>m>>n;
int a[m][n];
for(int i=0;i<m;i++)
{for(int j=0;j<n;j++)
  cin>>a[i][j];}
  int r=0;
for(int i=0;i<m-1;i++)
{
for(int j=i+1;j<m;j++)
{float s=0;
for(int k=0;k<n;k++)
  {s=s+((a[i][k]-a[j][k])*(a[i][k]-a[j][k]));}
  s=sqrt(s);
  if(abs(floor(s)-s)==0)
    r=r+1;
      }}
      cout<<r;}
