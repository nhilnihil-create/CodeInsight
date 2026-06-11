#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int n; cin >> n;
  int p[n];
  rep(i,n){
    cin >>p[i];
  }
  int cnt = 0;
  for(int i = 1; i < n-1; i++){
    if(p[i-1] < p[i] && p[i] < p[i+1])cnt++;
    if(p[i] < p[i-1] && p[i+1] < p[i])cnt++;
  }

  cout << cnt << endl;
	return 0;
}

