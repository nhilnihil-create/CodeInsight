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
  ll a;
  double b;
  cin >> a >> b;
  ll ib = b * 100 + 0.1;
  a *= ib;
  a /= 100;
  cout << a << endl;
}