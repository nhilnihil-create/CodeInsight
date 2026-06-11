#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int n, ans=1;
  cin >> n;
  vector<string> s(n), t(200000, "aaaaaaaaaaa");
  rep(i, n){
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  rep(i, n-1){
    if(s[i]!=s[i+1]){
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}