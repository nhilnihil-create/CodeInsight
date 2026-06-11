#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define inputInt(a) int a; cin >> a; 
#define inputInt2(a,b) int a; int b; cin >> a >> b; 
#define inputInt3(a,b,c) int a; int b; int c; cin >> a >> b >> c;
#define inputLong(a) long a;cin >> a; 
#define inputIntArray(a,N) int a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputLongArray(a,N) long a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputIntArray2(a,b,N) int a[N]; int b[N]; for(int i=0;i<N;i++){cin >> a[i] >> b[i];}
#define output(answer) cout << answer << endl;
#define fN(i,N)    for(int i=0; i<N; i++)
#define fSE(i,s,e) for(int i=s; i<=e; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,N) for(int i=0; i<N; i++)
#define cinv(v,N) vector<int> v(N); for(int i=0; i<N; i++){ cin >> v[i]; }
#define mt make_tuple
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define all(v) (v).begin(),(v).end()
const ll MOD2 = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//pair型のソート
bool compare_by_second(pair<ll,ll> a, pair<ll,ll> b){
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N, T; cin >> N >> T;
  vector<pair<ll,ll>> ab(N); FOR(i,N){ cin  >> ab[i].fi >> ab[i].se; }
  sort(all(ab));
  /*sort(all(ab),compare_by_second());
  reverse(all(ab));*/
  //FOR(i,N){ cout << ab[i].fi << ab[i].se << endl; }
  
  vector<ll> M(N);//b[i]以降の最大値。
  M[N-1] = ab[N-1].se;
  for(int i=N-2; i>=0; i--){
    M[i] = max(ab[i].se,M[i+1]);
  }
  
  //main
  ll ans = 0;
  vvll dp(N+1,vll(T+1,0));
  for(int i=1; i<=N; i++){//i種類目まで見る。
    for(int j=0; j<T; j++){//j分時点まででの満足度の最大値。
      if(j+ab[i-1].fi<T){
        dp[i][j+ab[i-1].fi] = max(dp[i][j+ab[i-1].fi],dp[i-1][j]+ab[i-1].se);
      }
      dp[i][j] = max(dp[i][j],dp[i-1][j]);
    }
  }
  for(int i=1; i<=N-1; i++){
    ans = max(ans,dp[i][T-1]+M[i]); 
  }
  ans = max(ans,dp[N][T-1]);
  
  // output
  cout << ans << endl;

  return 0;
}