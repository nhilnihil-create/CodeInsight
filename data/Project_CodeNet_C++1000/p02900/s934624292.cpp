#include <bits/stdc++.h>
using namespace std;
#define ln long long

int main () {
  ln a,b;
  cin >> a >> b;
  vector<pair<ln,int>> af;
  vector<pair<ln,int>> bf;
  int ac=0,bc=0;
  
  for(int i=2;i<=1000000;i++){
    if(a%i==0){
      af.push_back(make_pair(i,0));
      while(a%i==0){
        af[ac].second++;
        a/=i;
      }
      ac++;
    }
  }
  if(a!=1) af.push_back(make_pair(a,0));
  
  for(int i=2;i<=1000000;i++){
    if(b%i==0){
      bf.push_back(make_pair(i,0));
      while(b%i==0){
        bf[bc].second++;
        b/=i;
      }
      bc++;
    }
  }
  if(b!=1) bf.push_back(make_pair(b,0));
  
  int ans=1;
  
  for(pair<int,int> x:af){
    for(pair<int,int> y:bf){
      if(x.first==y.first) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}