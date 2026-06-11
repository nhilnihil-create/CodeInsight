#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(long long i = a; i < b; i++)
#define dump(a) for(auto x : a) cout << x << " "; cout << "\n"
#define print(a) cout << a << "\n"
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr << #x << ": " << x << ", " << #y << ": " << y << "\n"
#define debug3(x,y,z) std::cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << "\n"

typedef long long ll;
using vi   = vector<int>;
using vll  = vector<long long>;
using vs   = vector<string>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vvs  = vector<vector<string>>;

ll ttl = 0;
int n,m,q;

void dfs(vi a, vvi abcd, int now) {
  if (now < 0) {
    ll tmp_ttl = 0;
    rep(i,0,q) {
      if (a[abcd[i][1] - 1] - a[abcd[i][0] - 1] == abcd[i][2]) {
        tmp_ttl += abcd[i][3];
      }
    }
    ttl = max(ttl,tmp_ttl);
  } else {
    rep(i,a[now],m + 1) {
      a[now] = i;
      if (a[now] > a[now + 1]) break;
      dfs (a,abcd,now - 1);
    }
  }
}

int main() {
  cin >> n >> m >> q;
  vvi abcd(q,vi(4));
  
  rep(i,0,q) rep(j,0,4) {
    int tmp;
    cin >> tmp;
    abcd[i][j] = tmp;
  }
  vi a(n + 1,1); 
  a[n] = m; // 末尾に番兵
  
  dfs(a,abcd,n - 1);
  print(ttl);
  return 0;
}