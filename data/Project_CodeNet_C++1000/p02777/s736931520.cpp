#include<bits/stdc++.h>
using namespace std;
int main(void){
  pair<string,int> s,t;
  cin>>s.first>>t.first>>s.second>>t.second;
  string u; cin>>u;
  if(s.first==u) --s.second; else --t.second;
  printf("%d %d",s.second,t.second);
  return 0;
}
