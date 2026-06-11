#include <iostream>
using namespace std;

int main() {
  long long int a, b;
  while(cin >> a >> b) {
  long long int sum = a+b;
  //cout << sum << endl;
  

  int cnt = 1;
  while(sum /= 10) cnt++;

  cout << cnt << endl;
  }
}