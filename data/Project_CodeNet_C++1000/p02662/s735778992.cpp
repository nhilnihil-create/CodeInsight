/* This code is written by 18to_nhanh */
#define Tourist "169F"
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORs(i,a,b) for(int i=a;i<b;i++)
#define _FOR(i,a,b) for(int i=a;i>=b;i--)
#define _FORs(i,a,b) for(int i=a;i>b;i--)
using namespace std;
const int maxn = 3e3;
const int INF = 1e9;
const int MOD = 998244353;
const int base = 31;
const int LOG = 20;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pi> vpi;
typedef vector<vpi> vpii;
int n,s;
int a[maxn+5];
int dp[maxn+5][maxn+5];
void init(){
//    freopen(Tourist".inp","r",stdin);
//    freopen(Tourist".out","w",stdout);
}
void Time_Decreasing(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
void enter(){
    scanf("%d %d",&n,&s);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void solve(){
    dp[0][0] = 1;
    FOR(i,1,n){
         FOR(j,0,s){
             dp[i][j] = (dp[i][j] + 2 * dp[i-1][j]) % MOD;
             if(j - a[i] >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % MOD;
             }
         }
    }
    printf("%d\n",dp[n][s]);
//    FOR(i,0,n){
//        FOR(j,0,s){
//            printf("%d %d %d\n",i,j,dp[i][j]);
//        }
//    }
}
int main(){
    init();
    Time_Decreasing();
    enter();
    solve();
}
