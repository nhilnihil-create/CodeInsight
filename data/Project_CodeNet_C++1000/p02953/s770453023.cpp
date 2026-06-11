#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
	ll N;
  cin >> N;
  vector<ll> V(N);
  
  ll pre = 0;
  bool ok = true;
  for (int i = 0; i < N; i++) {
    ll ai;
    cin >> ai;
    
    if (pre < ai) {
      ai--;
    }
    if (pre > ai) {ok = false;}
   	pre = ai;
  }
  cout << (ok ? "Yes" : "No") << endl;
}