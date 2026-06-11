#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  string s; cin>>s;
  rep(i,s.size()){
    rep(j,n){
      if(s[i]!='Z') s[i]++;
      else s[i]='A';
    }
  }
  cout<<s<<endl;
}