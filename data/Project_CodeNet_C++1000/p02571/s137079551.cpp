#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  vector<int> same;
  string S, T;
  cin >> S >> T;
  int end = S.length() - T.length();
  for (int i = 0; i <= end; ++i) {
    int counter = 0;
    for (int j = 0; j < T.length(); ++j) {
       if (S[i + j] == T[j])
         ++counter;
    }
    same.push_back(counter);
    if (counter == T.length())
      break;
  }
  cout << T.length() - *max_element(same.begin(), same.end()) << endl;
  return 0;
}