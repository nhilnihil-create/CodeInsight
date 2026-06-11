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

#define umap unordered_map
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
const ll MOD = 1e9+7;

#define pll pair<ll,ll>

string s;
int N;
ll dp[100001][13];
int main(){
    cin>>s;
    N = s.size();
    FILL2(dp,100001,13,0LL);
    
    dp[0][0] = 1;
    for(int i=0;i<N;++i){
        int x;
        if(s[i]=='?'){ x = -1;}
        else{ x = ctoi(s[i]); }
        
        if(x<0){
            for(x=0;x<10;++x){
                for(int amari=0;amari<13;++amari){
                    int idx = (amari*10+x)%13;
                    dp[i+1][ idx ] += dp[i][amari];
                    dp[i+1][ idx ] %= MOD;
                }
            }
        }else{
            for(int amari=0;amari<13;++amari){
                int idx = (amari*10+x)%13;
                dp[i+1][ idx ] += dp[i][amari];
                dp[i+1][ idx ] %= MOD;
            }
        }
    }
    cout << dp[N][5] << "\n";
}
