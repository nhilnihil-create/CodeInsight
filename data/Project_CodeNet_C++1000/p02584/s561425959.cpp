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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,k,d;
    cin>>x>>k>>d;
    ll nt = min((abs(x)+d-1)/d,k);
    ll mini=INF;
    if(x>0)nt=-nt;
    rep(i,nt-10,nt+11){
        if(abs(i)>k)continue;
        mini = min(mini,abs(i*d+x + ((k-abs(i))%2)*d));
        mini = min(mini,abs(i*d+x - ((k-abs(i))%2)*d));
    }
    cout<<mini<<"\n";
    return 0;  
}   