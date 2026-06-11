#include<bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  vector<int> A = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
  for(int i = 0; i < 32; i++) {
    cin >> A.at(i);
  }
  cout << A.at(K-1) << endl;
}