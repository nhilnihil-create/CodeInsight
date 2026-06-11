#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  rep(i, N) cin >> p.at(i);
  sort(p.begin(), p.end()); 
  
  int sum = 0;
  rep(i, K) sum += p.at(i);
  cout << sum << endl;
}
