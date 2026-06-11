#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ii pair<double,double> 
int main() {
   
  int n;
  cin>>n;
  vector<int> p(n);
  vector<int> fact(n+1);
  fact[0]=fact[1]=1;
  for(int i=2;i<=n;i++)fact[i]=i*fact[i-1];
  double ans=0.0;
  for(int i=0;i<n;i++)p[i]=i;
  vector<ii> v(n);
  for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      v[i]={x,y};
  }
  do{
      double dis=0.0;
      for(int i=0;i<n-1;i++){
          dis+= sqrt((v[p[i]].f - v[p[i+1]].f)*(v[p[i]].f - v[p[i+1]].f) + (v[p[i]].s - v[p[i+1]].s)*(v[p[i]].s - v[p[i+1]].s));
          
      }
      ans+=dis;
  }while(next_permutation(p.begin(),p.end()));
  ans/=fact[n];
  cout<<fixed<<setprecision(9)<<ans;
}