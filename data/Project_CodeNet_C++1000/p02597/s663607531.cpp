#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
constexpr ll R=2e5+69, INF=2e9+6969;

int n,r,ans;
string S;

int main()
{
	cin >> n >> S;
	S = " " + S;
	for(int i=1;i<=n;++i)
	{
		if(S[i] == 'R') ++r;
	}
	for(int i=1;i<=r;++i) if(S[i] == 'W') ans++;
	printf("%d\n", ans);
	return 0;
}
