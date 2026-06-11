#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int K;
  cin >> K;

  vector<ll> a;
  FOR(i, 1, 9) a.push_back(i);

  int count = 0;
  while(1) {
    if(a.size() >= K) {
      cout << a[K-1] << endl;
      return 0;
    }
    K -= a.size();

    vector<ll> prev;
    swap(a, prev);
    for(ll x : prev) {
      for(int i=-1; i<=1; i++) {
        ll d = x%10 + i;
        if( d < 0 || d > 9) continue;
        ll nx = x*10 + d;
        a.push_back(nx);
      }
    }

  }
  return 0;
}
