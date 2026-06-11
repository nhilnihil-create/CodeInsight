#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};
//vector<int> bucket[MAX_N/1000];

int main(void){
    int N,T;
    cin >> N >> T;
    int A[N],B[N];
    rep(i,N) cin >> A[i] >> B[i];
    int dp1[N+1][T+1],dp2[N+1][T+1];
    rep(i,N+1) rep(j,T+1) dp1[i][j]=dp2[i][j]=-INF;
    rep(i,T+1) dp1[0][i]=dp2[N][i]=0;
    rep(i,N) rep(j,T){
        if(j+A[i]<=T) dp1[i+1][j+A[i]]=max(dp1[i+1][j+A[i]],dp1[i][j]+B[i]);
        dp1[i+1][j]=max(dp1[i+1][j],dp1[i][j]);
    }
    reprev(i,N) rep(j,T){
        if(j+A[i]<=T) dp2[i][j+A[i]]=max(dp2[i][j+A[i]],dp2[i+1][j]+B[i]);
        dp2[i][j]=max(dp2[i][j],dp2[i+1][j]);
    }
    int ans=0;
    rep(i,N) rep(j,T){
        int cmp=B[i];
        cmp+=dp1[i][j];
        cmp+=dp2[i+1][T-1-j];
        ans=max(ans,cmp);
    }
    cout << ans << endl;
}