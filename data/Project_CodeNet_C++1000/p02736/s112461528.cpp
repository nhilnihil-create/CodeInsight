/// Be Kind :)
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Os")

/*				So I ball So hard, muh'fuckas wanna find me					*/

/*				Bitch, where you when I was walkin'?
				Now I run the game, got the whole world talkin'				*/

/*				Niggas been counting me out
				I'm counting my bullets, I'm loading my clips
				I'm writing down names, I'm making a list					*/

/*				You never likes us anyway, fuck your friendship, I meant it */

/*				The Chanel or Balenciaga, Louis and Vuitton
				She know I got Fendi, Prada when I hit Milan				*/

/*				I ran away, I don't think I'm coming back home				*/

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e6+10, maxm=1e5+10, lg=23, mod=1e9+7, inf=1e18;

ll n,a[maxn],p;
bool mk[3];
char s[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n; for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<n;i++) a[i]=abs(s[i]-s[i+1]), mk[a[i]]=1;
	if(!mk[1])for(int i=1;i<n;i++) a[i]/=2;
	else      for(int i=1;i<n;i++) a[i]%=2;
	for(int i=0;i<n-1;i++)if(((n-2)&i)==i) p+=a[i+1];
	ll ans=p%2;
	if(!mk[1] && ans) ans=2;
	cout<<ans<<endl;
	
	return 0;
}

















