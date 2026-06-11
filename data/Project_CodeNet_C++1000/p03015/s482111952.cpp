#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int,int>;
using vi = std::vector<int>;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

ll dp[100005][2];

int main(){
    string L; cin >> L;
    int n = L.size();

    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int a=0;a<2;a++){
                for(int b=0;b<2;b++){
                    if(a && b) continue;
                    if(!j){
                        if(a + b > L[i]-'0') continue;
                        dp[i+1][j || a+b < L[i]-'0'] += dp[i][j];
                        dp[i+1][j || a+b < L[i]-'0'] %= mod;
                    }else{ // 未満確定
                        dp[i+1][j] += dp[i][j];
                        dp[i+1][j] %= mod;
                    }
                }
            }
        }
    }

    /* for(int i=0;i<=n;i++){ */
    /*     cout << "i = " << i << endl; */
    /*     for(int j=0;j<2;j++){ */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    cout << (dp[n][0] + dp[n][1])%mod << endl;
}
