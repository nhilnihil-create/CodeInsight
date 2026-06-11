#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  int k = 0;
  cin >> N;
  vector<int> A(N);
  for(int a = 0;a < N;a++)cin >> A[a];
  sort(A.begin(),A.end());
  cout << A[N / 2] - A[(N / 2)-1] << endl;
}