#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N); for (int i =0; i<N; i++) cin >> A.at(i);
  
  int maxA =0; int secondMaxA =0; int maxCount =0; int maxPoint =0;
  for (int i =0; i<N; i++) {
    maxA = max(A.at(i),maxA);
  }
  for (int i =0; i<N; i++) {
    if (A.at(i) == maxA) {
      maxCount++;
      maxPoint = i;
      if (maxCount >= 2) {
        break;
      } else {
        continue;
      }
    }
    secondMaxA = max(A.at(i),secondMaxA);
  }
  for (int i =0; i<N; i++) {
    if (maxCount ==1 && i == maxPoint) {
      cout << secondMaxA << endl;
    } else {
      cout << maxA << endl;
    }
  }
}