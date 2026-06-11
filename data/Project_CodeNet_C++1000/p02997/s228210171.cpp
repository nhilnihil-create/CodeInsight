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

signed main()
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> edge;
	vector<pair<int, int>> vs;
	if(K>(N-1)*(N-2)/2){
		cout << -1 << endl;
		return 0;
	}
	for(int i=2; i<=N; i++){
		edge.PB(pair<int, int>(1, i));
	}
	for(int i=2; i<=N-1; i++){
		for(int k=i+1; k<=N; k++){
			vs.PB(pair<int, int>(i, k));
		}
	}
	while(vs.size() != K){
		edge.PB(vs.back());
		vs.pop_back();
	}
	cout << edge.size() << endl;
	for(auto p: edge){
		cout << p.F << " " << p.S << endl;
	}
}