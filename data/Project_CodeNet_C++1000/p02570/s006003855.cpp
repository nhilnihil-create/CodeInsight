#include <iostream>
using namespace std;

int main() {
  int D, T, S;

  cin >> D >> T >> S;

  if(float(T) >= float(D) / float(S))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}