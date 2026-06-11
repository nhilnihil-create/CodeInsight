#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int H, N;cin >> H >> N;
  int A = 0;
  rep(i,N){
    int a; cin >> a;
    A += a;
  }
  bool ans = false;
  if(H <= A) ans = true;

  cout << (ans ? "Yes" : "No")  << endl;

	return 0;
}

