#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
  int N, M;
  while ( cin >> N >> M, N ) {

    vector<P> dat(N);
    for ( int i = 0; i < N; i++ ) {
      int d, p;
      cin >> d >> p;
      dat[i] = P(p, d);    
    }

    sort(dat.begin(), dat.end(), greater<P>());

    int ans = 0;
    for ( P i: dat ) {
      int p = i.first, d = i.second;
      if ( M < d ) ans += p*(d-M);
      M -= min(M, d);    
    }

    cout << ans << endl;
  }  
  return 0;
}


