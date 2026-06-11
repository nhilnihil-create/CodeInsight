#include <iostream>
using namespace std;

int main() {
  int n, ones_place;
  string ans;
  cin >> n;
  
  ones_place = n % 10;
  
  switch (ones_place) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      ans = "hon";
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      ans = "pon";
      break;
    case 3:
      ans = "bon";
      break;
  }
  
  cout << ans;
  
  return 0;
}