#include<bits/stdc++.h>
using namespace std;
#define li long int
int main(){
  string s;
  cin>>s;
  vector< li > v;
  li i=0,k;
  li l=s.length();
  while(i<l){
    k=0;
    while (s[i]=='<' && i<l ){
    ++k;++i;
    }
    if(k>0)
      v.push_back(k);
    k=0;
    while (s[i]=='>' && i<l){
    ++k;++i;
    }
    if(k>0)
      v.push_back(k);
  }
  long long int sm=0;
  for(auto x:v){
  	sm+=(x*(x+1))/2;
  }
  l=v.size();
  for(i=s[0]=='<' ? 0:1;i<l-1;i+=2){
  	sm-=min(v[i],v[i+1]);
  }
  cout<<sm<<"\n";
  return 0;
}