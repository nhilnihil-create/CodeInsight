#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  string t="";

  if(n%2!=0){
    cout << "No" << endl;
    return 0;    
  }

  rep(i,n/2){
    t+=s[i];
  }
  rep(i,t.size()){
    if(t[i] != s[i+n/2]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}
