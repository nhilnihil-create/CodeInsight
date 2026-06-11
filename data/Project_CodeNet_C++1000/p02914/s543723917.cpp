#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

const int N = (int)3e5;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
	else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
	if(b==0) return 1;
	else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
	else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
	if(kaijo_memo.size() > n) return kaijo_memo[n];
	if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
	while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
	return kaijo_memo[n];
}
ll nCr(ll n, ll r){
	if(n < r || r < 0) return 0;
	ll ret = 1;
	ret *= kaijo(n); ret %= MOD;
	ret *= mpow(kaijo(r), MOD-2); ret %= MOD;
	ret *= mpow(kaijo(n-r), MOD-2); ret %= MOD;
	return ret;
}

int main(void){
	int n;cin>>n;
	vector<vector<int>> A;
	rep(i,n){
		ll a;
		cin>>a;
		A.push_back(vector<int>());
		rep(j,60){
			A[i].push_back(a%2);
			a /= 2;
		}
		reverse(all(A[i]));
	}
	ll ans = 0;
	rep(c,60){
		int count = 0;
		rep(i,n){
			count += A[i][c];
		}
		if(count%2 == 1){
			ans += lpow((ll)2, 60-c-1);
			rep(i,n){
				A[i][c] = 0;
			}
		}
	}
	vector<bool> kitei;
	rep(i,n){
		kitei.push_back(false);
	}
	rep(c,60){
		int br = 0;
		while(br < n && (A[br][c] == 0 || kitei[br])){
			br++;
		}
		if(br == n){
			continue;
		}
		kitei[br] = true;
		rep(r,n){
			if(br == r) continue;
			if(A[r][c] == 1){
				rep(j, 60){
					A[r][j] ^= A[br][j];
				}
			}

		}
	}
	/*rep(i,n){
		rep(j,60){
			cerr<<A[i][j];
		}
		cerr<<endl;
	}*/

	vector<ll> count;
	
	rep(i,60){
		count.push_back(0);
	}
	rep(c,60){
		if(count[c] > 0){
			if(count[c]%2 == 1){
				ans += lpow((ll)2,60-c);
			}
			continue;
		}
		int r = 0;
		while(r < n && A[r][c] == 0){
			r++;
		}
		if(r == n) continue;

		rep(j,60){
			count[j] += A[r][j];
		}
		ans += lpow((ll)2,60-c);
	}
	cout<<ans<<endl;
	return 0;
}
