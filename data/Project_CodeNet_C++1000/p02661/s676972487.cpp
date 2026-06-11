#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  int mn[n],mx[n];
  for (int i=0; i<n; i++) cin >> mn[i] >> mx[i];
  sort(mn,mn+n);
  sort(mx,mx+n);
  if (n%2 == 0) {
    int l = mn[n/2]+mn[(n-1)/2],r = mx[n/2]+mx[(n-1)/2];
    cout << 2*(r/2) - 2*((l+1)/2) + 1 + (l%2) + (r%2)<< endl;
  }else {
    cout << mx[n/2] - mn[(n-1)/2] + 1 << endl;
  }
}