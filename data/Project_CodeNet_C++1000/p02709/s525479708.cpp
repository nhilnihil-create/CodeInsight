#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define X first
#define Y second
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;


template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int mod =(int)1e9+7;
const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll RS(ll N,ll P,ll M){
    if(P==0){
        return 1;
    }else{
        if(P%2==0){
            ll t=RS(N,P/2,M);
            return t*t%M;
        }else{
            return N*RS(N,P-1,M)%M;
        }
    }
}
bool greater_pair(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }else{
        return a.second>b.second;
    }
}
int main() {
    ios::sync_with_stdio(false);
    ll N=in();
    vector<pair<ll,ll>> A(N);
    REP(i,N){
        int a;
        cin>>a;A[i]=mp(a,i);
    }
    sort(all(A),greater_pair);
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,0));
    for(int i=0;i<N;i++){
        //iはこれまでに処理した個数
        REP(j,i+1){
            //jは左に送る数字の個数
            //i-jが右に送られている数字の個数
            if(dp[j+1][i-j]<dp[j][i-j]+(ll)A[i].first*(A[i].second-j)){
                dp[j+1][i-j]=dp[j][i-j]+(ll)A[i].first*(A[i].second-j);
            }
            // dp[j+1][i-j]=max(dp[j+1][i-j],dp[j][i-j]+A[i].first*(A[i].second-j));
            if(dp[j][i-j+1]<dp[j][i-j]+A[i].first*(ll)(N-(i-j)-1-A[i].second)){
                dp[j][i-j+1]=dp[j][i-j]+A[i].first*(ll)(N-(i-j)-1-A[i].second);
            }
        }
    }
    //REP1(i,N)REP(j,i+1)debug(dp[j][i-j]);


    ll final_ans=0;
    REP(i,N+1){
        if(final_ans<dp[i][N-i])
        final_ans=dp[i][N-i];
    }
    cout<<final_ans<<endl;
    return 0;
}
