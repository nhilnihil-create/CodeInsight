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
#define mod 998244353
#define INF2 1000000000000000000
#define int long long
int cnt[100010];

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
    int N; cin >> N;
    int D[100010];
    rep(i, N) cin >> D[i];
    int maximam = *max_element(D, D + N);
    rep(i, N) cnt[D[i]]++;
    if(D[0] != 0 || cnt[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1;
    rep(i, maximam) {
        ans = Mul(ans, power(cnt[i], cnt[i + 1]));
    }
    cout << ans << endl;




    return 0;
}
