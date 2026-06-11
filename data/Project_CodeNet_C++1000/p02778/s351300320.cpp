#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int k=s.size();
  string ans;
  rep(i,k){
    ans+='x';
  }
  cout << ans << endl;

  return 0;

}