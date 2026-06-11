#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll ans=min(k,a);
    k-=min(k,a);
    k-=min(k,b);
    ans-=min(k,c);
    cout<<ans<<endl;
}
