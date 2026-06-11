#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  if(N%2 == 1){
    cout << "No" << endl;
    return 0;
  }
  int n = N/2;
  if(S.substr(n) == S.substr(0,n)){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
