#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,k,r,s,p;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  ll ans=0;
  vector<bool> is(t.size(),true);
  for(int i=k;i<t.size();i++){
    if(t.at(i)==t.at(i-k) && is.at(i-k)==true){
      is.at(i)=false;
    }
  }
  rep(i,n){
    if(is.at(i)==true && t.at(i)=='r'){
      ans+=p;
    }
    if(is.at(i)==true && t.at(i)=='s'){
      ans+=r;
    }
    if(is.at(i)==true && t.at(i)=='p'){
      ans+=s;
    }
  }
  cout << ans;
}