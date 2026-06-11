#include <bits/stdc++.h>
using namespace std;

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int                                       long long
#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)
#define rlop(i,e,s)                               for(int i=e;i>=s;i--)
#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;
#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;

#define endl                                      '\n'
#define ff                                        first
#define ss                                        second
#define pii                                       pair<int,int>

#define pb                                        push_back
#define all(v)                                    v.begin(),v.end()

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

const int N = 3e3 + 7, M = 1000000007, inf = INT_MAX;
const long long INF = LLONG_MAX;

int n, Q;
int arr[N + 2], dp[N][N];
vector<pii> vec;

int get(int s, int e)
{
	if ( s > e ) return 0;

	int rem = e - s + 1;
	int &mafia = dp[s][e];
	if (mafia != -1) return mafia;

	int id = rem - 1;
	int a1 = abs(vec[id].ss - e) * vec[id].ff + get(s, e - 1);
	int a2 = abs(vec[id].ss - s) * vec[id].ff + get(s + 1, e);

	return mafia = max(a1, a2);
}


void solve()
{
	cin >> n;
	lop(i, 0, n) cin >> arr[i];
	lop(i, 0, n) vec.pb( {arr[i], i} );
	sort( all(vec));
	memset(dp, -1, sizeof dp);

	cout << get(0, n - 1);

}

int32_t main()
{
	ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);

	int test = 1;
	// cin >> test;
	while (test--)solve();


}



