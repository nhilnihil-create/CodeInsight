#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll s; cin >> s;
  ll x1 = 1e9, x2 = 1;
  ll y2 = (s+x1-1)/x1;
  ll y1 = x1*y2-s;
  cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2;
  cout << "\n";
  return 0;
}
