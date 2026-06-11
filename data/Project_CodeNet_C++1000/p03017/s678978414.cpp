#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VL vector<ll>
# define PII pair<int,int> 
# define VII vector<PII>
# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ld long double
# define FOR(i,a,b) for(int i = a ; i < b ; ++i) 
const ll inf = 1e18 ; 
const int MxN = 200000 ; 
int n ,a,b,c,d;
string s ; 


bool dfs(int p1, int dest) {
	for(int i = p1 ; i < dest ; ++i) {
		if(s[i] == '#' && s[i+1] == '#')
			return false ;
	}
	return true ; 
}

void solve() {

	cin >> n >>a >> b >>c >> d ; 
	a--;b--;c--;d--;
	//string s ; 
	cin >> s ; 
	bool ans= dfs(a,c) && dfs(b,d) ; 
	if(c < d) {
		cout << (ans ? "Yes" : "No") ; 
	} else {
		bool ok = false  ; 
		int cnt = 0 ;
		for(int i = b  ; i < min(d+1, n-1 ) ; ++i) {
			if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
				ok = true ; 
				break ; 
			}
		}
		if(ok) 
			cout << (ans ? "Yes" : "No" ); 
		else 
			cout << "No" ; 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	int  t =1; 
	//cin >> t ; 
	while(t--)
		solve() ; 
	return 0 ; 
}

