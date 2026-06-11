#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> h(N);
  for(int i=0; i<N; i++) cin >> h[i];
  sort(h.begin(),h.end());
  
  auto itr = lower_bound(h.begin(), h.end(), K);
  int index = distance(h.begin(), itr);
  
  cout << N-index << endl;
  
  
  return 0;
}
