#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t ans=0;
  map<pair<char,char>,int> m;
  string s;
  pair<char,char> p;
  for(int i=1;i<=N;i++){
    if(i%10==0){
      continue;
    }
    s=to_string(i);
    p=make_pair(s.front(),s.back());
    if(m.count(p)){
      m.at(p)++;
    }else{
      m[p]=1;
    }
  }
  char f,b;
  for(auto & x:m){
    tie(f,b)=x.first;
    p=make_pair(b,f);
    if(m.count(p)){
      ans+=x.second*m.at(p);
    }
  }
  cout << ans << endl;
  return 0;
}
