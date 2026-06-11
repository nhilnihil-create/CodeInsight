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

int main(){
    int N; cin>>N;
    string S; cin>>S;
    if(S[0]=='W' || S[2*N-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    vec v(2*N), zero(2*N), one(2*N); v[0] = one[0] = 0; zero[0] = 1;
    rep(i,2*N-1){
        if(S[i+1]!=S[i]) v[i+1]=v[i];
        else             v[i+1]=1-v[i];
        zero[i+1] = zero[i];
        one[i+1] = one[i];
        if(v[i+1] == 0) zero[i+1]++;
        else            one[i+1]++;
        if(one[i+1]>zero[i+1]){
            cout<<0<<endl;
            return 0;
        }
    }
    if(zero[2*N-1] != N){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    rep(i,2*N){
        if(v[i]==1){
            ans=(ans*(zero[i]-one[i]+1LL))%mod;
        }
    }
    FOR(i,1,N+1) ans=(ans*(ll)i)%mod;
    printf("%lld\n",ans);
    return 0;
}