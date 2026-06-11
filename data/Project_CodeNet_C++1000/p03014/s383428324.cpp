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

int U[2000][2000];
int D[2000][2000];
int L[2000][2000];
int R[2000][2000];

int main(){
    int H,W; cin>>H>>W;
    string board[H]; CINA(board,H);
    
    REP(i,H){
        REP(j,W){
            if(board[i][j]=='.'){
                if(j-1>=0){ L[i][j] = L[i][j-1]+1;}
                else{ L[i][j] = 1;}
            }else{
                L[i][j] = 0;
            }
        }
    }
    REP(i,H){
        REPR(j,W-1){
            if(board[i][j]=='.'){
                if(j+1<W){ R[i][j] = R[i][j+1]+1;}
                else{ R[i][j] = 1;}
            }else{
                R[i][j] = 0;
            }
        }
    }

    REP(j,W){
        REP(i,H){
            if(board[i][j]=='.'){
                if(i-1>=0){ U[i][j] = U[i-1][j]+1;}
                else{ U[i][j] = 1;}
            }else{
                U[i][j] = 0;
            }
        }
    }
    
    REP(j,W){
        REPR(i,H-1){
            if(board[i][j]=='.'){
                if(i<H-1){ D[i][j] = D[i+1][j]+1;}
                else{ D[i][j] = 1;}
            }else{
                D[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    int MAX = H+W-1;
    REP(i,H){
        REP(j,W){
            chmax(ans,L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
            if(ans==MAX){ break;}
        }
        if(ans==MAX){ break;}
    }
    

    cout << ans << "\n";
}
