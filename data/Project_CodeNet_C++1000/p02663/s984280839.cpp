#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int len1 = h1 * 60 + m1;
  int len2 = h2 * 60 + m2;
  len2 -= len1;
  len2 -= k;
  cout << len2 << endl;
}