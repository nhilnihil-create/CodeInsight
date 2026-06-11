#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  int N,A,B,C,D;  cin>>N>>A>>B>>C>>D;
  --A;  --B;  --C;  --D;
  string s; cin>>s;
  bool ok=true;
  char str='#';
  if(C<D){
    rep(i,B,D-1) if(s[i]==str && s[i+1]==str) ok=false;
    rep(i,A,C-1) if(s[i]==str && s[i+1]==str) ok=false;
  }else{
      rep(i,A,C-1) if(s[i]==str && s[i+1]==str) ok=false;
      rep(i,B,D-1) if(s[i]==str && s[i+1]==str) ok=false;
      if(ok){
        bool isok=false;
        rep(i,B,D+1) if(i-1>=0 && s[i-1]=='.' && s[i]=='.' && s[i+1]=='.' && i+1<=N-1){
          isok=true;
          break;
        }
        if(!isok) ok=false;
      }
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
