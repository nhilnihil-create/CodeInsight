#include <iostream>

using namespace std;

#define MAX_A_NUM 2000
#define MAX_M_NUM 2000

bool check(int n, int a[], int m, int i) {
  if(i == n) {
    if(m == 0) {
      return true;
    } else {
      return false;
    }
  }

  return check(n, a, m, i+1) || check(n, a, m - a[i], i+1);
}

int main() {
  int n, q, m;
  int a[MAX_A_NUM];
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  cin >> q;
  for(int i=0; i<q; i++) {
    cin >> m;
    if(check(n, a, m, 0)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}