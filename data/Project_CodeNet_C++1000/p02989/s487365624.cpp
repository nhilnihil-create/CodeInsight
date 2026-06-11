#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
  ll N;
  cin >> N;
  
  vector<ll> V(1e5+1);
  for (int i = 0; i < N; i++) {
  	ll bi;
    cin >> bi;
    V[bi] += 1;
  }
  
  ll cur = 0;
  for (int i = 1; i <= 1e5; i++) {
    cur += V[i];
    V[i] = cur;
  }
  
  if (N % 2 == 1) {
  	cout << 0 << endl;
    return 0;
  }
 
  ll cnt = 0;
  for (int i = 1; i <= 1e5; i++) {
  	if (V[i] == (N / 2)) {
    	cnt += 1;
    }
  }
  cout << cnt << endl;
}
