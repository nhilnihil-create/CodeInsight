#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;


int main() {
  int x; 
  cin >> x;
  vector<bool> prime(1000000);

  for (int i = 2; i < x; ++i) {
    if (prime[i] == true) continue;
    for (int j = i; j < 1000000; j += i) {
      prime[j] = true;
    }
  }

  for (int i = x; ; ++i) {
    if (!prime[i]) {
      cout << i << endl;
      return 0;
    }
  }
}