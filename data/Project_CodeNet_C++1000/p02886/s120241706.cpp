#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin >> N;
  vector<int> kazu(N);
  int count = 0;
  for(int i = 0; i < N; i++){
  	cin >> kazu[i];
    count += kazu[i];
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
  	ans += kazu[i]*(count-kazu[i]);
  }
  cout << ans/2 << endl;
  
}