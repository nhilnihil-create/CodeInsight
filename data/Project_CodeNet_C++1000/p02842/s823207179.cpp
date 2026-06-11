#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  int N; cin >> N;
  for(int i = 1; i <= 50000; i++){
    ll y = i * 1.08;
    if(y == N){
      cout << i << endl;
      return 0;
    } 
  }

  cout << ":(" << endl;
	return 0;
}
