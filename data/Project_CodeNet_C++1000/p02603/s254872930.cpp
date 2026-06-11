#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const int MAXN=100;
const ll MOD=10;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
ll A[MAXN];
void solve(){
    int N;
    cin>>N;
    for(int u=0;u<N;u++)cin>>A[u];
    int money=1000;
    int hd=0;
    while(hd<N){
        while(hd+1<N&&A[hd+1]<A[hd]){
            hd++;
        }
        int tl=hd;
        while(tl+1<N&&A[tl+1]>A[tl]){
            tl++;
        }
        money=money/A[hd]*A[tl]+money%A[hd];
        hd=tl+1;
    }
    cout<<money<<"\n";
}
void Ans(){
    int N;
    cin>>N;
    for(int u=0;u<N;u++)cin>>A[u];
    ll money=1000;
    for(int u=0;u<N;u++){
        if(A[u+1]>A[u]){
            money+=money/A[u]*(A[u+1]-A[u]);
        }
    }
    cout<<money<<"\n";
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    Ans();
}