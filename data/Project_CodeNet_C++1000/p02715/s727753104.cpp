#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

int isvisited[100010];
vector<int> enum_div(int n)//nの約数を列挙
{
	vector<int> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
int Mul(int a, int b) {
	return ((a % mod) * (b % mod)) % mod;
}
int square(int x) {
	return (x * x) % mod;
}

int power(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) return square(power(x, y / 2)) % mod;
	else return square(power(x, y / 2)) * x % mod;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int cnt[100010] = {};
    REP(i, 1, K) {
        cnt[i] = power(K/i, N);
    }
    RREP(i, K, 1) {
        vector<int> v = enum_div(i);
        for(auto& e: v) {
            if (i == e) continue;
            cnt[e] = (cnt[e] - cnt[i] + mod) % mod;
        }
    }
    int ans = 0;
    REP(i, 1, K) ans = (ans + Mul(i, cnt[i])) % mod;
    cout << ans << endl;

    return 0;
}
