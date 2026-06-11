#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i,n){
    if(s[i] != s[i-1]) ans ++;
  }
  cout << ans << endl;
}
