#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)998244353;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

ll power(ll a,ll n){
    if(n==0) return 1;
    ll res=1;
    while(n>0){
        if(n%2==1) res=res*a%MOD;
        a=a*a%MOD;
        n/=2;
    }
    return res;
}

int main(){
    ll N,ans=1,M=0,d;
    map<ll,ll> m;
    cin>>N;
    for(ll i=0;i<N;i++){
        ll D;
        cin>>D;
        if(i==0) d=D;
        m[D]++;
        M=max(M,D);
    }
    if(m[0]!=1||d!=0){
        cout<<"0"<<endl;
        return 0;
    }
    for(ll i=1;i<=M;i++){
        ans*=power(m[i-1],m[i]);
        ans%=MOD;
    }
    cout<<ans<<endl;
}