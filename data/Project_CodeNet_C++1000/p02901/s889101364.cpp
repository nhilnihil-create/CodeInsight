#include <math.h>
#include <assert.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <stack>
#include <array>
#include <random>
#include <chrono>
#include <climits>
#include <bitset>
using namespace std ;
#define int long long
#define ii pair<int,int>
#define FAST_IO ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL)
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
//const int N = 3e5+7 ;
const int INF = 1e18 ;
//const int MOD = 1e9 + 7 ;
int n , m ;
int dp[1001][1<<12] ;
int a[1001] ;
int p[1001] ;

int go(int idx, int mask){
	if(idx == m){
		if(mask == (1<<n)-1){
			return 0 ;
		}
		return INF ;
	}
	int& ans = dp[idx][mask] ;
	if(~ans){
		return dp[idx][mask] ;
	}
	ans = go(idx+1,mask) ;
	ans = min(ans, p[idx]+go(idx+1,mask|a[idx])) ;
	return ans ;
}

void solve(){
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int x , y ;
		cin >> x >> y ;
		for(int j = 0 ; j < y ; j++){
			int z ; cin >> z ;
			--z ;
			a[i] |= 1<<z ;
		}
		p[i] = x ;
	}
	ms(dp,-1) ;
	int ans = go(0,0) ;
	if(ans == INF) ans = -1 ;
	cout << ans ;
}

int32_t main(){
	FAST_IO ;
	int t = 1 ;
//	cin >> t ;
	while(t--){
		solve() ;
	}
}
