#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ld long double
const int MxN = 200001 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)
const int MOD = 1e9 + 7 ; 

/* VARIABLES */
int n  ;
/* END OF VARIABLES */



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	cin >> n ; 
	ll ans = 0 ; 
	vector<string> res ; 
	map<string,int> cnt ; 
	string s ; 
	FOR(i,0,n) {
		cin >> s ; 
		sort(s.begin(), s.end()) ; 
		cnt[s]++;
	}
	for(auto str : cnt) {
		int tmp = str.second ; 
		if(tmp > 1) {
			ans += ((ll)(tmp)*(tmp-1) )/2 ; 
		}
	}
	cout << ans ; 
	

		
	return 0 ; 
}

