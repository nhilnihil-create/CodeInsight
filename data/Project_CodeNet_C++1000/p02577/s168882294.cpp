#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N.length(); ++i) {
  	sum += N[i] - '0';
  }
  if (sum % 9 == 0)
    printf("Yes");
  else 
    printf("No");
  return 0;
}