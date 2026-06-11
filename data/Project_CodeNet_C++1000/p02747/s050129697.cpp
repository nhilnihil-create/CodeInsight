#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S;
  cin >> S;
  bool OK = true;
  if (S.size()%2==0) {
    for (int i=0; i<S.size()-1; i++) {
      if (i%2==0) {
        if (S[i]!='h'||S[i+1]!='i') {
          OK = false;
          break;
        }
      }
      else if (S[i]!='i'||S[i+1]!='h') {
        OK = false;
        break;
      }
    }
  }
  else OK = false;
  if (OK) cout << "Yes" << endl;
  else cout << "No" << endl;
}