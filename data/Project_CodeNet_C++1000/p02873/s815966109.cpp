#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  s='>'+s+'<';
  
  long ans=0;
  int n=s.size()-1;
  vector<int>b(n,-1);
  vector<int>c(n,-1);
  rep(i,n){
    if(s.at(i)=='>'&&s.at(i+1)=='<'){
      b.at(i)=0;
      c.at(i)=0;
    }
  }
  rep(i,n-1){
    if(b.at(i)>-1&&s.at(i+1)=='<'){
      b.at(i+1)=b.at(i)+1;
    }
  }
  for(int i=n-1;i>0;i--){
    if(c.at(i)>-1&&s.at(i)=='>'){
      c.at(i-1)=max(c.at(i)+1,c.at(i-1));
    }
  }
    
  rep(i,n){
    ans+=max(b.at(i),c.at(i));
  }
  cout<<ans<<endl; 
}