#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

bool compare_s(pair<ll, ll> a, pair<ll, ll> b){
	return a.second < b.second;
}

signed main()
{
	int N;
	cin >> N;
	vector<pair<ll, ll>> time;
	REP(i, N){
		ll A, B;
		cin >> A >> B;
		time.PB(pair<ll, ll>(A, B));
	}
	sort(ALL(time), compare_s);
	ll now = 0;
	REP(i, N){
		now += time[i].F;
		if(now > time[i].S){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
