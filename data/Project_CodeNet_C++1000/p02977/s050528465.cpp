#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define rrep(i,n) for(int i=1; i<=(n); ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define foreach(it, v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second

typedef unsigned int uint;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef set<int> si;

int N;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  if (N!=3 && N<5) cout << "No\n";
  else {
    if ((N&1)==0) {
      int x = 0;
      while(((N>>x)&1)==0) ++x;
      int p1 = 1 << x;
      int p2 = N - p1;
      ++p1;
      if (p2==0) {
        cout << "No\n";
        return 0;
      } else {
        cout << "Yes\n";
      }
      cout << p1 << " " << N << "\n";
      cout << p2 << " " << N*2 << "\n";
    } else {
      cout << "Yes\n";
    }
    int M = (N-1)/2;
    rep(i,M*2) cout << 1 << " " << (i+2) << "\n";
    rep(i,M) cout << (i*2+2) << " " << (i*2+3+N) << "\n";
    rep(i,M) cout << (i*2+3) << " " << (i*2+2+N) << "\n";
    cout << M*2+1+N << " " << N+1 << "\n";
  }
  return 0;
}
