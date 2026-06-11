//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

ll gcd(ll a,ll b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}

int dp[1000010];

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) dp[a[i]]++;
  bool f1=1;
  for(int i=2;i<=1000000;i++){
    itn cnt=0;
    for(int j=i;j<=1000000;j+=i){
      cnt+=dp[j];
      if(cnt>=2) f1=0;
    }
  }
  if(f1){
    cout << "pairwise coprime" << endl;
    return 0;
  }
  ll GCD=a[0];
  rep(i,n){
    GCD=gcd(GCD,a[i]);
  }
  if(GCD==1){
    cout << "setwise coprime" << endl;
    return 0;
  }
  cout << "not coprime" << endl;
}