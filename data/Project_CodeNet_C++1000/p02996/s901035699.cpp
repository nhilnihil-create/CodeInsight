#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  vector<pair<ll, ll>> work;
  for (int i = 0; i < N; i++) {
    ll A, B;
    cin >> A >> B;
    work.push_back({B,A});
  }
  
  sort(work.begin(), work.end());
  
  bool cond = true;
  
  ll time = 0;
  for (int i = 0; i < N; i++) {
    time += work[i].second;
    
    if (time > work[i].first) {
      cond = false;
      break;
    }
  }
  
  
  if (cond) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}