#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  string s;
  cin >> s;
  for(int i=0; i<s.size(); i += 2){
    if(s[i] == 'L'){
      cout << "No" << endl;
      return 0;
    }
    if(s[i+1] == 'R'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}