#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s; 
  cin >> s;
  int n=s.size();
  vector<int>ans(n+1);
  ans.at(0)=0;
  ans.at(1)=1;
  rep2(i,1,n){
    if(s.at(i)==s.at(i-1)){
      if(i>1){
        ans.at(i+1)=max(ans.at(i-1)+1,ans.at(i-2)+2);
      }
      else{
        ans.at(i+1)=ans.at(i-1)+1;
      }
    }
    else{
      ans.at(i+1)=max(ans.at(i)+1,ans.at(i-1)+1);
    }
  }
  
  cout<<ans.at(n)<<endl;
}