#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int h, n;
  int sum = 0;
  
  cin >> h >> n;
  for (int i=0; i < n; ++i) {
    int a_i;
    cin >> a_i;
    sum += a_i;
  }
  if (h <= sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
