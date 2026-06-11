#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n;
  cin >>n;
  string s;
  cin >> s;
  if(n%2==1){
    cout << "No" << endl;
    return 0;
  }
  int g=n/2;
  rep(i,g){
    if(s[i]!=s[i+g]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  

  return 0;

}
