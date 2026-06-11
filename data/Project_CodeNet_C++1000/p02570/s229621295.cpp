#include <iostream>
using namespace std;

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  if (t * s >= d) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}