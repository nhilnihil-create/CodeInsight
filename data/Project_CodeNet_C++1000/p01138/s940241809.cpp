#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    int N;
    cin >> N;
    if (N == 0) break;

    vector<int> table(86450, 0);
    for (int i = 0; i < N; i++) {
      string D;
      string A;
      cin >> D >> A;

      int DH = stoi(D.substr(0, 2)) * 3600;
      int DM = stoi(D.substr(3, 2)) * 60;
      int DS = stoi(D.substr(6, 2));
      int d = DH + DM + DS;

      int AH = stoi(A.substr(0, 2)) * 3600;
      int AM = stoi(A.substr(3, 2)) * 60;
      int AS = stoi(A.substr(6, 2));
      int a = AH + AM + AS;
      table.at(d)++;
      table.at(a)--;
    }

    for (int i = 0; i <= 86400; i++) {
      if (0 < i) table[i] += table[i - 1];
    }

    int M = 0;
    for (int i = 0; i <= 86400; i++) {
      if (M < table[i]) M = table[i];
    }

    cout << M << endl;
  }
}
