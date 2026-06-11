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
    ll n;
    cin>>n;
    ll a1[n],a2[n];
    REP(i,n){
        ll x,y;
        cin>>x>>y;
        a1[i]=x+y;
        a2[i]=x-y;
    }
    sort(a1,a1+n);
    sort(a2,a2+n);
    cout<<max(a1[n-1]-a1[0],a2[n-1]-a2[0])<<endl;
}
