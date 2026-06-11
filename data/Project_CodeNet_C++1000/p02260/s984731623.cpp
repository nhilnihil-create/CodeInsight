#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  int cnt = 0;
  for (int i=0; i<n; i++) {
    int min_j = i;
    for (int j=i; j<n; j++) {
      if (a[j] < a[min_j]) min_j = j;
    }
    if (i != min_j) {
      int temp = a[i];
      a[i] = a[min_j];
      a[min_j] = temp;
      cnt++;
    }
  }

  for (int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << cnt << endl;

  return 0;
}

