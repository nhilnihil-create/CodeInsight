#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

ll const mod = 1e9+7;

int up(int i,int k) {
  return (i+k-1)/k;
}

int main() {
  ll S,x=1e9;
  cin >> S;
  cout << 0 << ' ' << 0 << ' ';
  cout << x << ' ' << 1 << ' ';
  if (S%x==0) cout << S%x << ' ' << S/x << endl;
  else cout << x-S%x << ' ' << S/x+1 << endl;
}