#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n % 10 == 7 || (n % 100)/10 == 7 || (n % 1000)/100 == 7)
    cout << "Yes";
  else
	cout << "No";
  return 0;
}