#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  
  int n, k, R, S, P;
  cin>>n>>k;
  cin>>R>>S>>P;
  string x;
  cin>>x;
  char y,z;
  ll ans = 0;
  
  rep(i, n) {
    y = x.at(i);
    if(i<k){
      if(y=='r') ans+=P;
      else if(y=='s') ans+=R;
      else ans+=S;
    }
    else{
      z = x.at(i-k);
      if(y=='r'){
        if(z=='r') x.at(i)='a';
        else ans+=P;
      }
      else if(y=='p'){
        if(z=='p') x.at(i)='a';
        else ans+=S;
      }
      else{
        if(z=='s') x.at(i)='a';
        else ans+=R;
      }
    }
  }
  cout<<ans<<endl;
}