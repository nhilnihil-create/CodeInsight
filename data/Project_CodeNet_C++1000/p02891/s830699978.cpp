#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

// aaaxa aaaxa

ll solve(){
  string s; cin>>s;
  ll N = s.size();
  ll K; cin>>K;
  ll ans;
  ll a = 0;
  ll b = 0;
  bool flag = (s[0]==s[N-1]);
  if(flag){
    REP(i,N){
      if(s[i]==s[0]){++a;}
      else{ break;}
    }
    REPR(i,N-1){
      if(s[i]==s[N-1]){ ++b;}
      else{ break;}
    }
  }
  if(a==N){ ans = N*K/2; }
  else{
    string t = s;
    ans = 0;
    for(int i= a;i<N-b;++i){
      if(t[i+1]==t[i]){ t[i+1] = '0'; ++ans; }
    }
    ans *= K;
    ans += a/2;
    ans += b/2;
    if(flag){
      ans += ((a+b)/2)*(K-1);
    }
  }
  return ans;
}

int main(){
  cout << solve()<<"\n";
}