#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int main()
{
    int n,m;
  cin>>n>>m;
  int h[n+1];
  for(int i=1;i<=n;i++)
    cin>>h[i];
  vector<int>maxx(n+1);
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    maxx[u]=max(maxx[u],h[v]);
    maxx[v]=max(maxx[v],h[u]);
  }
  int count=0;
  for(int i=1;i<=n;i++)
  {
     if(h[i]>maxx[i])
       count++;
  }
 cout<<count<<endl;

  
  
  }
