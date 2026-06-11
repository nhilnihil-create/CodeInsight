#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  string s,t;
  cin >> s >> t;
  int m = s.size();
  int n = t.size();
  int k = 0;
  rep(i,m-n+1){
    int h=0;
    rep(j,n){
      if(s[i+j]==t[j]){
        h++;
      }
    }
    k = max(k,h);
  }
  cout << n-k << endl;
        
  return 0;

}