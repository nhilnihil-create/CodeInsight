#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007LL
#define nax 500009LL
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
 

ll pot(ll x, ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}
 

int main(){
	fastio;
    
	string l;

    cin>>l;
    int n=sz(l);
    int ans=0, x=0;
    REP(i,n){
        if(l[i]=='1'){
            ans=(ans+(pot(2,x)*pot(3,n-1-i))%mod)%mod;
            x++;
        }
    }
    ans=(ans+pot(2,x))%mod;
    
    cout<<ans;


	return 0;
}