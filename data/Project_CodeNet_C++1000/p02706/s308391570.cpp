#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> A(m);
  for (int i = 0; i < m; i++) {
    cin >> A[i];
  }
  int studyDay = 0;
  for (int i = 0; i < m; i++) {
    studyDay +=A[i];
  }
  if (n - studyDay >= 0) {
    cout << n - studyDay << endl;
  } else {
    cout << "-1" << endl;
  }

  return 0;
}
