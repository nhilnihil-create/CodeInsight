#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a = S.size();
  bool flag = false;
  for (int i = 0; i < a - 1; i++){
    if (i % 2 == 1) continue;
    if (S[i] == 'h' && S[i + 1] == 'i') flag = true;
  }
  if (flag == true && a % 2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}