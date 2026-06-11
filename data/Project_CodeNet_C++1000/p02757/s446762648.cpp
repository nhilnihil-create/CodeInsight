#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

lint powmod(lint a,lint b){
  return b?powmod(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;
}

int main(void){
    int N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    lint p[N+10]={};
    p[0]=1;
    rep(i,N+5) p[i+1]=(p[i]*10)%M;
    lint sum[N]={};
    lint cnt[M+50]={};
    lint ans=0;
    lint base=0;
    if(M==2){
        rep(i,N) if((S[i]-'0')%2==0) ans+=i+1;
        cout << ans << endl;
        return 0;
    }
    if(M==5){
        rep(i,N) if((S[i]-'0')%5==0) ans+=i+1;
        cout << ans << endl;
        return 0;
    }
    sum[0]=(S[N-1]-'0')%M;
    cnt[sum[0]]++;
    for(int i=1;i<N;i++){
        sum[i]=(sum[i-1]+p[i]*(S[N-1-i]-'0'))%M;
        cnt[sum[i]]++;
    }
    for(int i=0;i<N;i++){
        ans+=cnt[base];
        lint minus=(p[i]*(S[N-1-i]-'0'))%M;
        base=(base+minus+M)%M;
        cnt[sum[i]]--;
    }
    cout << ans << endl;
}
