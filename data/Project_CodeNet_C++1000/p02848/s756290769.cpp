#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] + N > 90) {
      S[i] = S[i] + N - 26;
    } else {
      S[i] = S[i] + N;
    }
  }
  cout << S << endl;
}