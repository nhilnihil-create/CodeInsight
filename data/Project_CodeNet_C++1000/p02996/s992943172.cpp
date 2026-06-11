#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  vector<pair<int64_t, int64_t>> vec(N);
  
  for (int i = 0; i < N; i++) {
    
    int64_t A, B; cin >> A >> B;
    
    vec[i].first = B; vec[i].second = A;
    
  }
  
  sort(vec.begin(), vec.end());
  
  int64_t total = 0;
  
  for (int i = 0; i < N; i++) {
    
    total += vec[i].second;
    
    if (vec[i].first < total) { cout << "No" << endl; return 0; }
    
  }
  
  cout << "Yes" << endl;
  
}