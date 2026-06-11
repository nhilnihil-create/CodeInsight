#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N;
  cin >> S >> T;
  string str = "";
  for (int i = 0; i < N; i++) {
    str += S[i];
    str += T[i];
  }
  cout << str << endl;
}