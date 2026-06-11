#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int MAX = 1000000000;

int main() {
  ll s;
  cin >> s;
  ll x1, x2, x3, y1, y2, y3;
  x1 = 0; y1 = 0;
  x2 = MAX, y2 = 1;
  x3 = (MAX - s % MAX) % MAX, y3 = (s + MAX - 1) / MAX;
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;

}