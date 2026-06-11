#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll INF = 1e16;
int main() {
  int n, k; cin >> n >> k;
  vector<int> p(n), c(n);
  rep(i, n){
    cin >> p[i];
    p[i]--;
  }
  rep(i, n) cin >> c[i];
  
  vector<vector<ll>> s(n, vector<ll>(n+1, -INF));
  vector<int> loop(n);
  int now;
  

  rep(i, n){
    s[i][0] = 0; now = i;
     rep(j, n){
        now = p[now];
    	s[i][j+1] = s[i][j] + c[p[now]];
     	if(now == i){ loop[i] = j+1; break;}
     }
    }

  ll score;
  ll ans = -INF;
  rep(i, n){
    score = s[i][1];
    if(k <= loop[i]){
	  rep(j, k) if(score < s[i][j+1]) score = s[i][j+1];
    }
    if(k > loop[i] && s[i][loop[i]] > 0){
	  rep(j, n){
        if(score < s[i][j+1] + s[i][loop[i]]*((k-(j+1))/loop[i]))
			score = s[i][j+1] + s[i][loop[i]]*((k-(j+1))/loop[i]);
      }
    }
    if(k > loop[i] && s[i][loop[i]] <= 0){
	  rep(j, n) if(score < s[i][j+1]) score = s[i][j+1];
    }

    if(ans < score) ans = score;
    }
      
  cout << ans << endl; 
      
   return 0;
}
