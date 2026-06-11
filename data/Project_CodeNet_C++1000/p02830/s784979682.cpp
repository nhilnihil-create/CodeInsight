#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int a;
  cin >> a;
  string s,t;
  cin >> s >> t;
  rep(i,a){
    cout << s[i] << t[i] ;
  }
  
  return 0;

}