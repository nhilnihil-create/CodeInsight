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
typedef pair<int, int> P;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int A[510];
    rep(i, N) cin >> A[i];
    int sum = 0;
    rep(i, N) sum += A[i];
    int ans = 1;
    vector<int> v = enum_div(sum);
    for(auto& e: v) {
        vector<P> cost;
        int sumL = 0, sumH = 0;
        rep(i, N) {
            int H = A[i] % e;
            int L = e - A[i] % e;
            //cout << A[i] << " " << e << " " << H << " " << L << endl;
            cost.push_back({L, H});
            sumL += L;
        }
        bool ok = false;
        int c = INF;
        sort(cost.begin(), cost.end(), greater<P>());
        rep(i, N) {
            if(max(sumL, sumH) <= K) ok = true;
            c = min(c, max(sumL, sumH));
            sumL -= cost[i].first;
            sumH += cost[i].second;
        }
        if(ok) ans = max(ans, e);
        //cout << "*" << e << " " << c << endl;
    }
    cout << ans << endl;


    return 0;
}
