#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int n;
  string s, ans="Yes";
  cin >> n >> s;
  if(n%2==1)ans="No";
  rep(i, n/2){
    if(s[i]!=s[n/2+i]){
      ans="No";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}