#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n-1; i >= 0; i--) {
    cout << a[i];
    if (i != 0) cout << " ";
  } 
  cout << endl;
  return 0;
}