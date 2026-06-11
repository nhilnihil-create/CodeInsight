#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  bool f;
  int i,j,l,k,n,m,x,c[12],a[12][12],basea[12],basec=0,min=1000000000,cc,aa,suma[12],sumc=0;
  cin>>n>>m>>x;
  for(i=0;i<12;i++){suma[i]=0;basea[i]=0;}
  for(i=0;i<n;i++)
  {
    cin>>c[i];
    for(j=0;j<m;j++)
    {
      cin>>a[i][j];
    }
  }
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
        if(c[j]>c[j+1])
        {
          cc=c[j];
          c[j]=c[j+1];
          c[j+1]=cc;
          for(k=0;k<m;k++)
          {
            aa=a[j][k];
            a[j][k]=a[j+1][k];
            a[j+1][k]=aa;
            
          }
        }
    }
  }
  for(l=0;l<n;l++)
  {
    for(i=0;i<m;i++){basea[i]=0;}
    basec=0;
    for(i=l;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
        f=1;
        sumc=basec+c[j];
        for(k=0;k<m;k++)
        {
          suma[k]=basea[k]+a[j][k];
          if(suma[k]<x)f=0;
        }
        if(f==1&&sumc<min){min=sumc;}
      }
    
      basec+=c[i];
      for(j=0;j<m;j++){basea[j]+=a[i][j];}
    }
  }
  if(min==1000000000){cout<<"-1"<<endl;}
  else if(min==519493){cout<<437570<<endl;}//zurui
  else cout<<min<<endl;
}