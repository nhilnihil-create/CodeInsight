#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
      std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair


int main(){
    ll N; cin>>N;
    ll a[N+1];
    for(int i=1;i<=N;++i){
        cin >> a[i];
    }
    ll left_r[N+1];
    ll left_b[N+1];
    ll left_g[N+1];

    left_r[1] = 0;
    left_b[1] = 0;
    left_g[1] = 0;
    
    for(int i=1;i<N;++i){
        left_r[i+1] = left_r[i];
        left_b[i+1] = left_b[i];
        left_g[i+1] = left_g[i];
        if(left_r[i]==a[i]){
            left_r[i+1] += 1;
        }else if(left_b[i]==a[i]){
            left_b[i+1] += 1;
        }else{
            left_g[i+1] += 1;
        }
    }
    
    ll ans = 1;
    for(int i=1;i<=N;++i){
        ll num = 0;
        num += (left_r[i]==a[i]);
        num += (left_b[i]==a[i]);
        num += (left_g[i]==a[i]);
        ans *= num;
        ans %= MOD;
    }
    
    cout << ans << "\n";
}