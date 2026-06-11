#include <bits/stdc++.h>
using namespace std;

int main() {
  int counter = 0;
  int N;
  cin >> N;
  vector<int> data(N);
  for (int i=0; i<N; i++) {
    cin >> data[i];
  }
  sort(data.begin(),data.end());
  cout << data[N/2]-data[N/2-1];
}