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

bool judge_bigger(int x,int p,vint A,int m,int n,int v){
  if(x < p) return true;
  int key = A[x] + m;
  if(A[p-1] > key) return false;
  int sum = 0;
  sum += (p-1)*m;
  sum += (n-x)*m;
  rep(i,p-1,x){
    sum += min(m,key-A[i]);
  }
  return sum >= v*m;
}

signed main(){
  int n,m,v,p;
  cin >> n >> m >> v >> p;
  vint A(n);
  rep(i,0,n) cin >> A[i];
  sort(A.rbegin(),A.rend());
  int ok = -1;
  int ng = n;
  while(abs(ok - ng) > 1){
    int mid = (ok + ng)/2;
    if(judge_bigger(mid,p,A,m,n,v)){
      ok = mid;
    }
    else{
      ng = mid;
    }
  }
  cout << ok + 1 << endl;
}