#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i,n){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      ans ++;
    }
  }
  cout << ans << endl;
  return 0;
}
