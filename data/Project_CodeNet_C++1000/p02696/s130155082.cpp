#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(),v.end())
#define sorta(A,N) sort(A,A+N)
#define rep(i,a,N) for(ll i=a;i<N;i++)
#define test(T) ll T; cin>>T; while(T--)
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
/*ll gcd(ll a,ll b){
    if(!a)
        return b;
    else
        return gcd(b%a,a);
}
ll N=1e7+1;
vector<ll>prime(N);
ll power(ll a,ll b){
    a%=MOD;
    ll res=1;
    while(b){
        if(b&1)
            res*=a%MOD;
        a*=a%MOD;
        b>>=1;
    }
    return res;
}
void sieve(){
    rep(i,0,N) prime[i]=i;
    for(ll i=4;i<N;i+=2)
        prime[i]=2;
    for(ll i=3;i*i<N;i+=2){
        if(prime[i]==i)
            for(ll j=i*i;j<N;j+=i)
                if(prime[j]==j)
                    prime[j]=i;
    }
}
vector<ll> factor(ll N){
    vector<ll> fac;
    while(N!=1){
        fac.pb(prime[N]);
        N/=prime[N];
    }
    return fac;
}*/
void solve(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double A,B,N,x;
    cin>>A>>B>>N;
    if(N>=B) x=B-1;
    else x=N;
    cout<<floor(A*x/B)-A*floor(x/B);
}
int main(){
    speed;
    solve();
}
