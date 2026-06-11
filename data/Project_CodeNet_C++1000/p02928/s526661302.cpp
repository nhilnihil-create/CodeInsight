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
#define MOD 1000000007;
#define int long long
using P = pair<int,int>;
signed main(){
  int n,k;
  cin >> n >> k;
  vint A(n);
  rep(i,n) cin >> A[i];
  vint FIRST(n);
  vint down(n);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(A[i] > A[j]){
        down[i]++;
        if(i < j) FIRST[i]++;
      }
    }
  }
  //rep(i,n) cout << FIRST[i] << " " << down[i] << endl;
  int num = k*(k-1)/2;
  //cout << num << endl;
  num %= MOD;
  int ans = 0;
  rep(i,n){
    ans += FIRST[i]*k;
    ans %= MOD;
    ans += down[i]*num;
    ans %= MOD;
  }
  cout << ans << endl;
}