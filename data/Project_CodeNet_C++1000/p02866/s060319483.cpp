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
#define INF 100000000000000009
#define MOD 1000000007
#define int long long
using P = pair<int,int>;
signed main(){
  int n;
  cin >> n;
  vint to(n);
  int d;
  cin >> d;
  to[d]++;
  bool flag = true;
  if(d != 0) flag = false;
  rep(i,n-1){
    int d;
    cin >> d;
    to[d]++;
  }
  int ans = 1;
  bool flag2 = true;
  for(int i = 1;i < n;i++){
    if(to[i] == 0) flag2 = false; 
    if(flag2){
      //cout << pow(to[i-1],to[i]) << endl;
      int count = to[i];
      while(count--){
        ans *= to[i-1];
        ans %= 998244353;
      }
    }
    else{
      if(to[i] > 0) flag = false;
    }
    //cout << ans << endl;
  }
  if(flag && to[0] == 1) cout << ans << endl;
  else cout << 0 << endl;
}