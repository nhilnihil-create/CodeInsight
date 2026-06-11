#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int>count(N+2);
  count.at(0) = -1;
  count.at(1) = 0;
  count.at(2) = 1;
  for (int i = 3; i < N+2; i++) {
    if (S.at(i-2) == S.at(i-3)){
      count.at(i) = count.at(i-3) + 2;
    }
    else{
      count.at(i) = count.at(i-1) + 1;
    }
  }
  cout << count.at(N+1) << endl;
}


