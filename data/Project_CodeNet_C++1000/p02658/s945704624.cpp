#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  bool zero = false;
  long long res = 1, input;
  vector<long long> numbers;
  for (int i = 0; i < n; ++i) {
  	cin >> input;
  	if (!input) {
  		zero = true;
  		break;
  	}
  	numbers.push_back(input);
  }
  if (zero)
	res = 0;
  else {
  	  for (int i = 0; i < n; ++i) {
	      if (res > 1000000000000000000 / numbers[i]) {
	          res = -1;
	          break;
	      }
          res *= numbers[i];
      }
  }
  cout << res;
  return 0;
}