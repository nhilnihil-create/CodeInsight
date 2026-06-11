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

vint calc(vint old){
  int n = old.size();
  vint ans(n);
  rep(i,0,n){
    int MIN = max((int)0,i - old[i]);
    int MAX = min(n-1,i + old[i]);
    ans[MIN]++;
    if(MAX+1 < n)ans[MAX+1]--;
  }
  rep(i,0,n-1){
    ans[i+1] += ans[i];
  }
  return ans;
}

signed main(){
  int n,k;
  cin >> n >> k;
  vint A(n);
  rep(i,0,n) cin >> A[i];
  int s = log(n)/log(2);
  int num = min(s*10,k);
  rep(i,0,num){
    A = calc(A);
  }
  rep(i,0,n) cout << A[i] << " ";
}