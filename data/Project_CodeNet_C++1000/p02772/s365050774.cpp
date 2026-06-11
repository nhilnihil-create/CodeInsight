#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, a;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> a;
    if((a % 5 != 0 && a % 3 != 0) && a % 2 == 0){
      cout << "DENIED";
      return 0;
    }
  }
  cout << "APPROVED";
  return 0;
}
