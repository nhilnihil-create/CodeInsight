#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007LL
#define nax 200009LL
#define FOR(i,n,m) for(int i = (n); i < (m); i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())

 
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;

const ll N=1e6;

int main(){
	fastio;

	ll a, b; cin>>a>>b;

    ll x=a, y=b;
    
    set<ll> s;
    
    for(ll i=2; i<=N; i++){
        if(a%i==0) s.insert(i);
        while(a%i==0){
            a/=i;
        }
    }
    if(a>1) s.insert(a);

    for(ll i=2; i<=N; i++){
        if(b%i==0) s.insert(i);
        while(b%i==0){
            b/=i;
        }
    }
    if(b>1) s.insert(b);
    ll ans=0;
    for(ll j : s){
        if(x%j==0 && y%j==0) ans++;
    }

    cout<<ans+1;


	return 0;
}
