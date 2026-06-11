#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, K;
  cin >> N >> K;
  int h[N];
  rep(i,N) h[i] = 0;
  rep(i,K) {
  	int d;
    cin >> d;
    rep(j,d) {
    	int a;
      cin >> a;
      a--;
      h[a]++;
    }
  }
  
  int ans = 0;
  rep(i,N) if (h[i]==0) ans++;
  cout << ans << endl;
	return 0;
}