#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin>>N>>K;
  map<int,int>mp;
  for(int X=0;X<K;X++){
    int D;cin>>D;
    for(int Y=0;Y<D;Y++){
      int A;cin>>A;mp[A]++;
    }
  }
  int U=0;
  for(auto p:mp){
    auto V=p.second;U++;
  }
  cout<<N-U<<endl;
}