#include <iostream>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  A *= 100;
  B *= 100;
  long long res = -1;
  for (int i = 0; i < 100000; i++){
    if ((i * 8 - A) < 100 && (i * 8 - A) >= 0){
      if ((i * 10 - B) < 100 && (i * 10 - B) >= 0){
        res = i;
        break;
      }
    }
  }
  cout << res << endl;
}