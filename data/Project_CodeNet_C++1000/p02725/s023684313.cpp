#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,k;
  cin >> k >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int dist = 0;
  for(int i = 1; i < n; i++) {
    dist = max(a[i]-a[i-1],dist);
  }
  dist = max(k+a[0]-a[n-1],dist);

  cout << k-dist << endl;
  return 0;
}
