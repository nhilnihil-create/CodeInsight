#include <bits/stdc++.h>
using namespace std;

int main(){
  string S, T;
  cin >> S >> T;
  
  vector<int> check((int)S.size(), 0);
  int count = 0;
  
  for (int i=0; i<S.size() - T.size()+1; i++){
    for (int j=0; j<T.size(); j++){
      if (S.at(i+j) == T.at(j)) count++;
    }
    check.at(i) = count;
    count = 0;
  }
  
  sort(check.begin(), check.end(), greater<int>());
  cout << (int)T.size() - check.at(0) << endl;
}