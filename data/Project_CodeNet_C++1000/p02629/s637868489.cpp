#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  N--;
  long long M = 26;
  int count = 1;
  for (int i = 0; i < 11; i++) {
    if (N < M){
      break;
    }
    else {
      N -= M;
      M *= 26;
      count++;
    }
  }
  M /= 26;
  
  vector<int>A(count);
  for (int i = 0; i < count; i++) {
    A.at(i) = N/M;
    N -= A.at(i)*M;
    M /= 26;
    A.at(i) += 97;
    printf("%c",A.at(i));
  }
  cout << endl;
}
  