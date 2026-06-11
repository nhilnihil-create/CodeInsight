#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  // cout << s.substr(0 + (n / 2), 1);

  if(n%2 ==0 ){
    if(s.substr(0,n/2) == s.substr(n/2,n/2)){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
