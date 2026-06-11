#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  string s;
  cin>>s;
  string hitachi = "";
  rep(i,5){
    hitachi+="hi";
    if (hitachi == s){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}