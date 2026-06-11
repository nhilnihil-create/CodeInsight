#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s,u;
  int q;
  cin>>s>>q;
  int ct=0;
  rep(i,q){
    int t;
    cin >> t;
    if(t==2){
      int f;
      char c;
      cin >> f >> c;
      if(f==2){
        s+=c;
      }else{
        u+=c;
      }
    }else{
      swap(s,u);
      ct++;
    }
  }
  string ans;
  reverse(u.begin(),u.end());
  ans=u+s;
  
  cout << ans;
}
  
