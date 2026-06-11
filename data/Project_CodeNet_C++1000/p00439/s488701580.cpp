#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef pair<int, int> P_i;
typedef pair<double,double> P_d;
#define rep(i,n) for(int i=0;i<(n);++i)
#define alrep(i,j,n) for(int i=0;i<(n);++i)for(int j=i+1;j<(n);++j)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;int ans=0;
#define answer cout << ans << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed main(){
  int N,k;
  while(cin >> N >> k && (N!=0 || k!=0)){
    int sum[N+1]={};
    int ans=-1*INF;
    for(int i=1;i<=N;i++){
      int a;
      cin >> a;
      sum[i]=sum[i-1]+a;
    }
    rep(i,N-k){
      int res=sum[i+k]-sum[i];
      chmax(ans,res);
    }
    cout << ans << endl;
  }
  return 0;
}

