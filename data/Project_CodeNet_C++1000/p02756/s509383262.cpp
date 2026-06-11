#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  deque<char> p;
  rep(i,s.size()){
    p.push_back(s[i]);
  }
  int q; cin>>q;
  bool rev=false;
  rep(qi,q){
    int t; cin>>t;
    if(t==1){
      if(rev) rev=false;
      else rev=true;
    }else{
      int f;
      char c; 
      cin>>f>>c;
      if(!rev){
        if(f==1) p.push_front(c);
        else p.push_back(c);
      }else{
        if(f==2) p.push_front(c);
        else p.push_back(c);
      }
    }
  }
  if(rev) reverse(p.begin(),p.end());
  string ans;
  while(!p.empty()){
    ans+=p.front();
    p.pop_front();
  }
  cout<<ans<<endl;
}
