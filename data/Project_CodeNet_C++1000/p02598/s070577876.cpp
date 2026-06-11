#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e17 + 9;
ll n,k;
ll vet[maxn];
bool check(int mid){
    ll cont=0;
    rep(i,0,n){
        cont+=(vet[i]+mid-1)/mid-1;
    }
    return cont<=k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rep(i,0,n){
        cin>>vet[i];
    }
    ll ini=1,mid,fim=1e9;
    ll ans=-1;
    while(ini<=fim){
        mid = (ini+fim)>>1;
        if(check(mid)){
            ans=mid;
            fim=mid-1;
        }
        else ini=mid+1;
    }
    cout<<ans<<'\n';
    return 0;  
}   