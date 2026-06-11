#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> b;
  map<int,bool> f;
  int m=0;
  for(int _=0;_<n;_++){
    int a;
    cin>>a;
    b[a]++;
    f[a]=1;
    m=max(a,m);
  }
  for(auto a:b){
    if(a.second>1)
      f[a.first]=0;
    for(int i=2;a.first*i<=m;i++)
      if(b.count(a.first*i))
        f[a.first*i]=0;
  }
  int c=0;
  for(auto a:f)
    c+=(a.second?1:0);
  cout<<c<<endl;
}