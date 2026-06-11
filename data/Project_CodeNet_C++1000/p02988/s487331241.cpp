#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  int P[N]; for (int i = 0; i < N; i++) cin >> P[i];
  int count = 0;
  for (int i = 1; i < N-1; i++) {
    if ((P[i-1] - P[i]) * (P[i] - P[i+1]) >= 0) count++;
  }
  cout << count << endl;
}