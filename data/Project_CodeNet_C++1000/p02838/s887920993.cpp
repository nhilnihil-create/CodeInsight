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
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
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

multiset<lint> decomp(lint N){
    multiset<lint> res;
    lint num=N;
    for(lint i=2;i*i<=num;i++){
        while(N%i==0) N/=i,res.insert(i);
        if(N==1) break;
    }
    if(N!=1) res.insert(N);
    return res; 
}

int main(void){
    int N;
    cin >> N;
    lint A[N];
    rep(i,N) cin >> A[i];
    lint ans=0;
    rep(i,60){
        lint zero=0,one=0;
        rep(j,N){
            if(A[j]&(1LL<<i)) one++;
            else zero++;
        }
        lint mul=(zero*one)%MOD;
        lint mul2=(1LL<<i)%MOD;
        ans=(ans+mul*mul2)%MOD;
    }
    cout << ans << endl;
}
