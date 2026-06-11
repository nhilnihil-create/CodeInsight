#include <iostream>

using namespace std;


bool lucky7(int n) {
  for(; n > 0; n = n / 10) {
    if(n % 10 == 7) {
      return true;
    }
  }

  return false;
}

int main() {
  int N;
  cin >> N;

  if(lucky7(N)) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}

