/**
*    author:  yuya1234
*    created: 22.07.2020 09:18:22
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long double eps = 1.0E-14;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a,T b){return gcd(a,b)*(a/gcd(a,b))*(b/gcd(a,b));}

int MOD=1000000007;

long long fibo(int n, vector<long long> &memo) {
    // ベースケース
    if (n == 0) return 0;
    else if (n == 1) return 1;

    // メモをチェック (既に計算済みなら答えをリターンする)
    if (memo[n] != -1) return memo[n];

    // 答えをメモしながら、再帰呼び出し
    return memo[n] = (fibo(n-1, memo) + fibo(n-2, memo)) % MOD;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(15);

  int n,m;
  cin>>n>>m;

  int a[m+1];
  bool flg=false;
  FOR(i,0,m-1)
  {
    cin>>a[i];
    if(i!=0 && a[i-1]+1==a[i])flg=true;
  }
  a[m]=n+1;

  if(flg)
  {
    cout<<0<<endl;
    return 0;
  }

  ll sum=1;
  vector<ll> memo(n+2, -1);
  FORD(i,m,1)
  {
    //cout<<a[i]<<" "<<a[i-1]<<" "<<a[i]-a[i-1]<<" "<<fibo(a[i]-a[i-1]-1,memo)<<endl;
    sum*=fibo(a[i]-a[i-1]-1,memo);
    sum%=MOD;
  }

  //cout<<a[0]<<" "<<fibo(a[0],memo)<<endl;
  sum*=fibo(a[0],memo);
  sum%=MOD;

  cout<<sum<<endl;

  return 0;
}