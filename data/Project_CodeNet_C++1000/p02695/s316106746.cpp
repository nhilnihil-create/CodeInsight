#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

vector<string> num;
void dfs(int n, int m, string res){
  if(n == 0){
    num.push_back(res);
    return;
  }
  for(char c = res.back(); c <= m+'0'; c++){
    dfs(n-1,m,res+c);
  }
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m,q; cin >> n >> m >> q;
  vi a(q),b(q),c(q),d(q);
  rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];

  dfs(n,m,"1");
  int ans = 0;
  rep(i,num.size()){
    int res = 0;
    rep(j,q){
      if(num[i][b[j]]-num[i][a[j]] == c[j]) res += d[j];
    }
    chmax(ans,res);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
