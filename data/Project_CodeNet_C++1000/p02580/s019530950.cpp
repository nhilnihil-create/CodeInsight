#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int H, W, M; cin >> H >> W >> M;
  int row[H]={}, col[W]={};
  set<pii> s;
  int r_max = 0, c_max = 0;
  rep(i,M){
    int h, w; cin >> h >> w;
    h--, w--;
    s.insert({h,w});
    row[h]++;
    col[w]++;
    chmax(r_max, row[h]);
    chmax(c_max, col[w]);
  }
  ll cnt_r = 0, cnt_c = 0;
  rep(i,H) if (row[i]==r_max) cnt_r++;
  rep(i,W) if (col[i]==c_max) cnt_c++;

  int cnt_b = 0;
  for (auto p : s){
    int r = p.first, c = p.second;
    if (row[r]==r_max && col[c]==c_max) cnt_b++;
  }
  if (cnt_r*cnt_c>cnt_b) cout << r_max+c_max << endl;
  else cout << r_max + c_max - 1 << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}