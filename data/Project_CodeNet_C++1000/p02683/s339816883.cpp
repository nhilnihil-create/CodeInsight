#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VL vector<ll>
# define PII pair<int,int> 
# define VII vector<PII>
# define mp make_pair
# define pb push_back
# define vt vector
# define PI acos(-1)
# define ld long double
# define endl "\n"
# define all(c) (c).begin(), (c).end()
# define ft first 
# define sd second 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i) 
# define F0R(i,b) for(int i = 0 ; i < b ; ++i) 
# define RF0R(i,b) for(int i = b ; i >= 0 ; --i) 
const ll inf = 1e18 ; 
const int MxN = 100001 ; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	int n , m , x; 
	cin >> n >> m >> x ; 
	vt<int> c(n) ; 
	vt<vt<int>> A(n,vt<int>(m)) ; 
	
	F0R(i,n) {
		cin >> c[i] ; 
		F0R(j,m) 
			cin >> A[i][j] ; 
	}
	int ans = INT_MAX ; 
	F0R(i,(1<<n)) {
		int cost = 0 ; 
		vt<int> skills(m) ; 
		F0R(j,n) {
			if((i>>j)&1) {
				//cout << 1 ; 
				F0R(k,m)
					skills[k] += A[j][k] ; 
				cost += c[j] ;
			} 
			//cout <<0;
		} 
		//cout << endl ; 
		bool ok = true ;
		F0R(j,m) {
			if(skills[j] < x) {
				ok = false ;
				break ;
			}
		}
		if(ok) {
			ans = min(ans , cost ) ; 
		}
	}
	if(ans == INT_MAX) 
		cout << -1 ; 
	else 
		cout << ans; 
	return 0 ; 
}


