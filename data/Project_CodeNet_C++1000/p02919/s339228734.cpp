#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
	int N; cin >> N;
	vector<Pi> P(N);
	rep(i,N) cin >> P[i].first,P[i].second = i;
	sort(P.rbegin(),P.rend());
	multiset<int> s;
	s.insert(-1);
	s.insert(-1);
	s.insert(N);
	s.insert(N);
	s.insert(P[0].second);
	ll ans = 0;
	repr(i,1,N){
		auto p1 = s.lower_bound(P[i].second);
		p1++;
		int n1 = *p1;
		p1--;
		int n2 = *p1;
		p1--;
		int n3 = *p1;
		p1--;
		int n4 = *p1;
		ans += (ll)(n1-n2)*(P[i].second-n3)*P[i].first;
		ans += (ll)(n2-P[i].second)*(n3-n4)*P[i].first;
		s.insert(P[i].second);
	}
	cout << ans << endl;
}

