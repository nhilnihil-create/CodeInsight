#include<iostream>
using namespace std;

int main() {
  string S; cin >> S;
  int N = S.size();
  int d[N];
  for (int i = 0; i < N; i++) d[i] = -1;
  for (int i = 0; i < N-1; i++) {
    if (S[i] == 'R' && S[i+1] == 'L') d[i] = d[i+1] = 0;
  }
  for (int i = 0; i < N; i++) {
    if (d[i] == 0) {
      if (S[i] == 'R') {
        for (int j = i-1; j >= 0 && d[j] == -1 && S[j] == 'R'; j--) d[j] = i-j;
      } else {
        for (int j = i+1; j < N && d[j] == -1 && S[j] == 'L'; j++) d[j] = j-i;
      }
    }
  }
  int c[N]; for (int i = 0; i < N; i++) c[i] = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      if (d[i] % 2 == 0) c[i+d[i]]++;
      else c[i+d[i]+1]++;
    } else {
      if (d[i] % 2 == 0) c[i-d[i]]++;
      else c[i-d[i]-1]++;
    }
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << c[i];
  }
  cout << endl;
}