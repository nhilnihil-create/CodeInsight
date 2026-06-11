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
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,k;
  cin >> n >> k;
  int sum = (n-2)*(n-1)/2;
  vector<vbool> ans(n,vbool(n));
  rep(j,1,n){
    ans[0][j] = true;
  }
  if(k > (n-2)*(n-1)/2){
    cout << -1 << endl;
    return 0;
  }
  int num = 1;
  int plus = 1;
  int time = sum - k;
  while(time > 0 && num != n){
    // cout << num << " " << plus << endl;
    ans[num][num+plus] = true;
    plus++;
    time--;
    if(num + plus == n){
      num++;
      plus = 1;
    }
  }
  int aaa = 0;
  rep(i,0,n) rep(j,0,n) if(ans[i][j]) aaa++;
  cout << aaa << endl;
  rep(i,0,n){
    rep(j,0,n){
      if(ans[i][j]) cout << i + 1 << " " << j + 1 << endl;
    }
  }
}