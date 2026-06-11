#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 2e5;
const ll inf = 1e18;
const ll mod = 1e9 + 7;



int main(){
	fastio;
	ll tc,n,m,t,tt,f,q;
	deque<char> dq;
	char c;
	string s;
	cin >> s;
	f(i,0,s.size()) dq.push_back(s[i]);
	ll rev = 0;
	cin >> q;
	while(q--){
		cin >> t;
		if(t == 1) rev = 1-rev;
		else{
			cin >> f >> c;
			f--;
		//	cout << f << " " << c << endl;
			if(f == rev) dq.push_front(c);
			else dq.push_back(c);
		} 
	}
	if(rev){
		for (auto it = dq.rbegin(); it != dq.rend(); ++it) 
        cout << *it ; 
	}
	else{
		for (auto it = dq.begin(); it != dq.end(); ++it) 
        cout << *it ; 
	}
}