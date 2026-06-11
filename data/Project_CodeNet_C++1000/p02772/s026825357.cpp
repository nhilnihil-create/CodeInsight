#include <iostream>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int A = 0;
    cin >> A;
    
    if (A % 2 == 0) {
      if (!(A % 3 == 0 || A % 5 == 0)) {
        cout << "DENIED" << endl;
  		return 0;
      }
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}