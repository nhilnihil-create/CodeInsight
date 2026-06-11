#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = (1LL << 60);
 const int INFI = (1 << 30);

    int main(){
      string s, t; cin >> s >> t;
      int N = s.size();
      int M = t.size();

      s += s;

      vector<vector<int>> pos(26);
      for (int i = 0; i < 2 * N; i++) pos[s[i] - 'a'].push_back(i);

      bool ok = true;
      for (int i = 0; i < M; i++){
        if (pos[t[i] - 'a'].size() == 0) ok = false;
      }

      if (!ok) cout << -1 << endl;

      else {
        ll ans = -1;
        for (int i = 0; i < M; i++){
          auto itr = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), ans % N);
          ans += *itr - ans % N;
        }
        cout << ans + 1 << endl;
      }
    }
