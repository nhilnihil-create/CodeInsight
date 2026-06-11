#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}



int main() {
  int N,K;
  cin >> N >> K;
  int tmp=N*(N-1)/2;
  if (K>(N-1)*(N-2)/2) {
    cout << -1 << endl;
    return 0;
  }

  cout << tmp-K << endl;
  rep(i,N-1) {
    rep2(j,i+1,N) {
      // cout << "##" << tmp << endl;
      if (tmp>=K) {
        cout << i+1 << ' ' << j+1 << endl;
        tmp--;
      }
      if (tmp==K) return 0;
    }
  }
}