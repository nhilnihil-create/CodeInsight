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
#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,n;
    cin>>x>>n;
    set<ll> s;
    REP(i,n){
        ll t;
        cin>>t;
        s.insert(t);
    }
    ll maxx=LONG_MAX;
    ll ans;
    for(ll i=-100;i<=200;i++){
        if(s.count(i)){
            continue;
        }
        ll diff=abs(i-x);
        if(diff<maxx){
            maxx=diff;
            ans=i;
        }
    }
    cout<<ans<<endl;
}
