#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  while (N != 0) {
    vector<int> s(N);
    double ave = 0;
    for (int i=0; i<N; i++) {
      cin >> s[i];
      ave += s[i];
    }
    ave /= N;

    double sd = 0;
    for (int i=0; i<N; i++) {
      sd += pow(s[i] - ave, 2);
    }
    sd /= N;

    printf("%.5f\n", sqrt(sd));

    cin >> N;
  }

  return 0;
}

