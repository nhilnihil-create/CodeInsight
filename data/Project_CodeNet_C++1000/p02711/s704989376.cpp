#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string s;
  cin >> s;

  rep(i,s.size()){
    if(s.at(i) == '7'){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

}
