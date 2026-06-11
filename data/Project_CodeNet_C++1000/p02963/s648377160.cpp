#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll S;
  cin>>S;
  ll t = (S-1LL)/1000000000LL+1LL;
  cout<<0<<" "<<0<<" "<<t<<" "<<1<<" "<<t*1000000000-S<<" "<<1000000000<<endl;
}