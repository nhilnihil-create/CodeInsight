#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N,K;
	cin >> N >> K;
	vector<int> p(N);
	rep(i,N) cin >> p[i];
	sort(p.begin(), p.end());
	int S = 0;
	rep(i,K) S += p[i];
	cout << S << endl;

  return 0;
}
