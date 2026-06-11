#include <iostream>
using namespace std;

int main() {
	int n;
  cin >> n;
  int c = n;
  if (n % 1000 == 0){
    cout << "0";
  }
  else {
    n/=1000;
    n += 1;
    int k = n * 1000;
    cout << k - c;
  }
	return 0;
}
