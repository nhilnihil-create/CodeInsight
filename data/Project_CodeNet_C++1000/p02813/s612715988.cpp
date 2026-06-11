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
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi p(n),q(n),num(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  rep(i,n) num[i] = i+1;
  int a,b, cnt = 0;
  do{
    cnt++;
    bool ok1 = true, ok2 = true;
    rep(i,n){
      if(num[i] != p[i]) ok1 = false;
      if(num[i] != q[i]) ok2 = false;
    }
    if(ok1) a = cnt;
    if(ok2) b = cnt;
  }while(next_permutation(all(num)));
  cout << abs(a-b);
  cout << endl;
  return 0;
}
