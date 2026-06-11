#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n,d,a;
  cin >> n >> d >> a;
  vector<P> X(n);
  rep(i,n) cin >> X[i].first >> X[i].second;
  sort(X.begin(),X.end());
  queue<P> que;
  int ans = 0;
  d = d*2;
  int tot = 0;
  rep(i,n){
    int x = X[i].first;
    int h = X[i].second;
    while(que.size() > 0 && que.front().first < x){
      tot -= que.front().second;
      que.pop();
    }
    h -= tot;
    if(h > 0){
      int num = (h+a-1)/a;
      ans += num;
      int dmg = num*a;
      tot += dmg;
      que.push(P(x+d,dmg)); 
    }
  }
  cout << ans << endl;
}