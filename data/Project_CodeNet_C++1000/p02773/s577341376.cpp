#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  string s;
  map<string,int> poll;
  for(int i=0; i<N; i++){
    cin>>s;
    poll[s]++;
  }
  int mv=0;
  for(auto x : poll){
    auto v=x.second;
    if(v>mv) mv=v;
  }
  for(auto x : poll){
    if(x.second==mv){
      cout<<x.first<<endl;
    }
  }
}