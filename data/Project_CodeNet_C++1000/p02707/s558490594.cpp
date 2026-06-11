#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> company(N, 0);
  for (int i = 0; i < N-1; i++) {
    int tmp;
    cin >> tmp;
    company[tmp-1]++;
  }
  for (int i = 0; i < N; i++) cout << company[i] << endl; 
}
