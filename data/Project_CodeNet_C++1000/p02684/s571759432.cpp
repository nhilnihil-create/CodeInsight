#include <bits/stdc++.h>
using namespace std;

# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ff first 
# define ss second 
# define endl '\n'
# define vt vector
# define all(c) (c).begin(), (c).end()
# define FOR(i,a,b) for(int i = a ; i < b ; ++i) 
# define F0R(i,b) for(int i = 0 ; i < b ; ++i) 

typedef long long ll ; 
typedef long double ld ; 
typedef pair<int,int> pii ; 
typedef pair<ll,ll> pll ;



const ll inf = 1e9 ; 
const int MxN = 500001; 
const int mod = 1e9+7 ; 


int n ; ll k ; 
vt<int> a(MxN) ; 


void solve() {
	cin >> n >> k ; 
	FOR(i,1,n+1) cin >> a[i] ; 
	vt<int> b ;
	set<int> ans;
	int i = a[1] ;
	map<int,int> m1 ; 
	int cnt = 0 ; 
	while(1) {
		if(m1[i] == 1)
			break ;
		b.pb(i) ;  
		m1[i]++; 
		cnt++ ;
		if(cnt == k) {
			cout << i ;
			return ;  
		}
		i = a[i] ; 
	}
	//cout << i << endl ;
	int j = 0 ;
	while(1) {
		if(b[j] == i)
			break; 
		else{ 
			j++ ;
			k--; 
		}

	}
	vt<int> c ;
	//cout << j << endl ; 
	while(j < b.size()) {
		c.pb(b[j]) ; 
		j++;
	}
	//for(int x : c) cout << x << ' ' ; 
	k = k % c.size() ;
	
	if(k==0) 
		cout << *c.rbegin();  
	else
	cout << c[k-1] ; 




}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	int t =1; 
	//cin >> t ;
	while(t--) solve() ; 
	
	return 0 ; 
	
}

