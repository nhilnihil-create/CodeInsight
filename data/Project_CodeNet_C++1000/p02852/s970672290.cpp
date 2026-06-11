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
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
typedef stack<ll> ST;
typedef queue<ll> QUE;
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

struct Seg{
    vec dat;
    //要素数
    int n;

    Seg(int n_){
        n=1;
        while(n<n_)n*=2;
        dat.resize(2*n);

        for(int i=0;i<2*n-1;i++)
            dat[i]=INF;
    }

    //k番目の値をaに変更
    void update(int k,ll a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }

    //[a,b)の最小値を求める
    //kは節点の番号、[l,r)はその区間
    ll query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l)return INF;
        if(a<=l && r<=b)return dat[k];
        else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
};

int main(){
    int N,M; cin>>N>>M;
    string S; cin>>S;
    Seg seg(N+M);
    vec dp(N,INF);
    seg.update(N,0);
    for(int i=N-1;i>=0;i--){
        if(S[i]=='1') continue;
        ll res=seg.query(i+1,i+M+1,0,0,seg.n);
        if(res==INF){
            cout<<-1<<endl;
            return 0;
        }
        dp[i]=1+res;
        seg.update(i,dp[i]);
    }
    vec ans={0}; ll k=dp[0];
    rep(i,N){
        if(dp[i]==k-1){
            ans.pb(i);
            k--;
        }
    }
    ll m=dp[0];
    rep(i,m-1) cout<<ans[i+1]-ans[i]<<" ";
    cout<<N-ans[m-1]<<endl;
    return 0;
}