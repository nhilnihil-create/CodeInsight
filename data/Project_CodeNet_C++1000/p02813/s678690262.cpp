#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {

  int N; cin >> N;
  vector<int> P(N);
  vector<int> Q(N);
  rep(i,N) cin >> P[i];
  rep(i,N) cin >> Q[i];
  vector<int> v(N);
  //1刻みで格納できる関数、便利
  iota(v.begin(), v.end(), 1);
  int cnt = 0;
  int a,b;
  do{
    cnt++;
    if(v == P) a = cnt;
    if(v == Q) b = cnt;
  }while(next_permutation(v.begin(),v.end()));
  
  int ans = abs(a - b); 
  cout << ans << endl;


	return 0;
}