#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> A(3);
  rep(i, 3) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  if(A.at(0)==A.at(1) && A.at(0)!=A.at(2)) cout << "Yes" << endl;
  else if(A.at(1)==A.at(2) && A.at(0)!=A.at(1)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


