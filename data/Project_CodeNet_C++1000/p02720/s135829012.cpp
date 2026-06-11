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

vector<ll> U;
void dfs(ll a, int digit){
  if (digit>10) return;

  U.push_back(a);
  // cout << a << endl;

  int start = a ? max(0,(int)(a%10-1)) : 1, stop = a ? min(9,(int)(a%10+1)) : 9;
  for (int i=start;i<=stop;i++){
    dfs(a*10+i,digit+1);
  }
}

int main(){
  int K; cin >> K;
  dfs(0,0);
  sort(all(U));
  // cout << U.size() << endl;
  cout << U[K] << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}