#include <iostream>
using namespace std;

int a[256];

int main() {
  int h; cin >> h;
  for (int i = 1; i <= h; i++)
    cin >> a[i];

  for (int i = 1; i <= h; i++) {
    cout << "node " << i;
    cout << ": key = " << a[i];
    if (i != 1) cout << ", parent key = " << a[i/2];
    if (2*i <= h) cout << ", left key = " << a[2*i];
    if (2*i+1 <= h) cout << ", right key = " << a[2*i+1];
    cout << ", " << endl;
  }

  return 0;
}