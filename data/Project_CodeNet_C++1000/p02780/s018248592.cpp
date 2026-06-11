#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
using G = vector<map<int, int>>;

int 
main() {
  int N, K; cin >> N >> K;
  vector<double> arr(N);
  rep(i, 0, N) cin >> arr[i];
  vector<double> ex(1001);
  for(double i = 1; i < 1001; i++){
    ex[i] = (1 + i) / 2;
  }

  double comp = 0;
  rep(i, 0, K){
    comp += ex[arr[i]];
  }

  double ans = comp;
  for(int i = 1; i <= N - K; i++){
    comp = comp - ex[arr[i - 1]] + ex[arr[K + i - 1]];
    if(ans < comp) ans = comp;
  }

  cout << fixed << setprecision(10) << ans << endl;

}