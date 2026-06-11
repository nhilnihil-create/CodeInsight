#include<iostream>
using namespace std;
int p[200005];
  int s[200005];
 int find(int v)
  {
if(v==p[v])
  return v;
    return p[v]=find(p[v]);
  }
  
  void uni(int a,int b)
  {
     a=find(a);
    b=find(b);
    if(a!=b)
    {   p[b]=a;
    s[a]+=s[b];
    }
    }

int main()
{
int n,m;
  cin>>n>>m;
  
    for(int i=0;i<n+1;i++)
    { 
      p[i]=i;
      s[i]=1;
    }
    
    
  int a,b;
  while(m--)
  {
  cin>>a>>b;
    uni(a,b);
  }
  int ma=0;
  for(int i=1;i<n+1;i++)
    if(ma<s[i])
      ma=s[i];
  cout<<ma<<endl;
}