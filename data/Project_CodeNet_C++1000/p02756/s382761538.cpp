#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s; cin>>s;
  deque<char> s1,s2;
  for(auto& i:s){ s1.push_front(i); s2.push_back(i);}
  int cnt=0,q; cin>>q;
  for(int i=0; i<q; ++i){
    int Q; cin>>Q;
    if(Q==1) cnt^=1;
    else{
      int f; char c;
      cin>>f>>c;
      if(f-1==cnt){ s1.push_back(c); s2.push_front(c);}
      else{ s1.push_front(c); s2.push_back(c);}
    }
  }
  if(cnt) for(auto i:s1){ cout<<s2.back(); s2.pop_back();}
  else for(auto i:s2){ cout<<s1.back(); s1.pop_back();}
  return 0;
}