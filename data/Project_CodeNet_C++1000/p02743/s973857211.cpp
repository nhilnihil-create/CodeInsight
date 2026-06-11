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
  ll a, b, c;
  cin >> a >> b >> c;
  if (c - a - b < 0) {
    cout << "No" << endl;
    return 0;
  }
  ll left = 4 * a * b;
  ll right = c - a - b;
  right *= right;
  if (left < right) cout << "Yes" << endl;
  else cout << "No" << endl;

}