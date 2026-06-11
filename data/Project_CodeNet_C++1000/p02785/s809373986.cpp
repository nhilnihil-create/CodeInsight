#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> H(n);
  rep(i,n) cin >> H[i];
  sort(H.begin(),H.end());
  ll cnt = 0;
  rep(i,n-k) cnt += H[i];
  cout << cnt << endl;
}
