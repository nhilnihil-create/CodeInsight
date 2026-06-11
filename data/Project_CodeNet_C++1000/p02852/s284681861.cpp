#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  vint ans;
  int now = n;
  bool flag = true;
  while(n != 0){
    flag = false;
    if(now > m){
      rep(i,now-m,now){
        if(s[i] == '0'){
          ans.push_back(now-i);
          now = i;
          flag = true;
          // cout << now << endl;
          break;
        }
      }
    }
    else{
      rep(i,0,now){
        if(s[i] == '0'){
          ans.push_back(now-i);
          now = i;
          flag = true;
          // cout << now << endl;
          break;
        }
      }
    }
    if(!flag) break;
  }
  if(now != 0) cout << -1 << endl;
  else{
    int n = ans.size();
    rep(i,0,n){
      cout << ans[n-1-i] << " ";
    }
  }
}