#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;
int N;

void dfs(string s) {
  // v から行ける各頂点 next_v について
  if(SZ(s)==N){
    cout << s << endl;
    return;
  }
  char c='a';
  rep(i,SZ(s)) chmax(c,s[i]);
  for (int i=0;i<=c-'a'+1;i++) {
    string S="";
    char c2='a'+i;
    S=s+c2;
    dfs(S); // 再帰的に探索
  }
}

signed _main(){
  cin >> N;
  dfs("a");
  return 0;
}
