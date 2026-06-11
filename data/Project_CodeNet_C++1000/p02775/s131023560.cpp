//69行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

//Simple Array Input
#define SAI int n;cin >> n;vi a(n);ain(a)
//Simple Graph Input
#define SGI(m) for(int i=0;i<m;i++){int a,b;cin >> a >> b;g[--a].pb(--b);g[b].pb(a);}
//Simple Tree Input
#define STI SGI(n-1)

typedef long long ll;
typedef long long integer;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){
    for(int i=0;i<a.size();i++)cout << a[i] << (i < a.size()-1 ? ' ' : '\n');
}
///////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	cin.tie(0);ios::sync_with_stdio(false);
//	cout<<fixed<<setprecision(20);

	string s;cin >> s;
	reverse(all(s));
	int n = s.size();

	vector<vector<ll>> dp(n+1,vector<ll>(2,1e18));
    dp[0][0] = 0;
	rep(i,n){
		//j == 1
		{
			chmin(dp[i+1][1],dp[i][1] + 10 - (s[i] - '0' + 1));
			chmin(dp[i+1][0],dp[i][1] + (s[i] - '0' + 1));
		}

		//j == 0
		{
			chmin(dp[i+1][1] , dp[i][0] + 10 - (s[i] - '0'));
			chmin(dp[i+1][0] , dp[i][0] + (s[i] - '0'));	
		}
	}
	cout << min(dp[n][0],dp[n][1] + 1) << '\n';
	return 0;
}