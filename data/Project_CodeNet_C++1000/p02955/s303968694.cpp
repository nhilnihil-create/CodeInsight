#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

int N;ll K;
vec A;
bool b(ll d){
    vec r;
    rep(i,N){
        if(A[i]%d==0) continue;
        r.pb(A[i]%d);
    }
    sort(all(r));
    int R=SZ(r);
    vec S(R+1),T(R+1);S[0]=T[0]=0;
    rep(i,R){
        S[i+1]=S[i]+r[i];
        T[i+1]=T[i]+d-r[R-1-i];
    }
    FOR(i,1,R){
        if(S[i]==T[R-i] && S[i]<=K) return true;
    }
    return false;
}

int main(){
    scanf("%d %lld",&N,&K);
    A.resize(N);ll sum=0;
    rep(i,N){
        scanf("%lld",&A[i]);
        sum+=A[i];
    }
    ll ans=1,M=(ll)sqrt(sum)+1;
    FOR(i,1,M){
        if(sum%i!=0) continue;
        if(b(i)) ans=max(ans,(ll)i);
        if(b(sum/i)) ans=max(ans,sum/i);
    }
    printf("%lld\n",ans);
    return 0;
}