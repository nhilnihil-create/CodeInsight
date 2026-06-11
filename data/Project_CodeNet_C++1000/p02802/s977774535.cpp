#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, A = 0, W = 0;
  cin >> N >> M;
  vector<int> a(N, 0), b(N, 0);
  for(int i = 0;i < M;i++) {
    int p;
    string s;
    cin >> p >> s;
    if(a[p-1] == 0) {
      if(s == "AC") {
        a[p-1] = 1;
        A++;
      } else {
        b[p-1]++;
      }
    }
  }
  for(int i = 0;i < N;i++) {
    if(a[i] == 1) W += b[i];
  }
  cout << A << " " << W << endl;
}