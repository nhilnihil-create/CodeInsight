#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  long long zenbu=0;
  for(int i=0; i<N; i++){
    zenbu ^= A.at(i);
  }

  for(int i= 0; i<N-1; i++){
    cout << (zenbu ^A.at(i)) << " ";
  }
  cout << (zenbu ^ A.at(N-1)) << endl;
}