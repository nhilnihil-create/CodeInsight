#include <bits/stdc++.h>
 
#define f(i,a,b) for( ll i = a; i < (ll) b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= (ll) b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
 
const ll MAX= 3e5+100;

ll l[MAX],r[MAX];

int main(){
	fastio;
	ll tc,n,k,c,w,ind;
	string s;
	cin>>n>>k>>c>>s;
	ind=0,w=0;
	while(w<k){
		if(s[ind]=='x') ind++;
		else{
			l[w++]=ind;
			ind+=(c+1);
		}
	}
	ind=n-1,w=k-1;
	while(w>=0){
		if(s[ind]=='x') ind--;
		else{
			r[w--]=ind;
			ind-=(c+1);
		}
	}
//	f(i,0,k) cout<<l[i]<<" "<<r[i]<<endl;
	f(i,0,k) if(l[i]==r[i]) cout<<l[i]+1<<endl;
  	return 0;	
}