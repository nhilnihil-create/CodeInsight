#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,count=0;  cin>>n;
  vector<int>  v(n);
  rep(i,n)cin>>v.at(i);
  
  rep(i,n-2){
    if(v.at(i)<v.at(i+1)&&v.at(i+1)<v.at(i+2)){
      count++;}
    if(v.at(i)>v.at(i+1)&&v.at(i+1)>v.at(i+2)){
      count++;}
  }
  cout<<count;
}

