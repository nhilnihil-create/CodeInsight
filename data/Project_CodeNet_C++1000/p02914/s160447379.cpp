#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 44100
#define LOGMAXN 20
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n;
ll v[MAXN];
int freq[MAXN];

ll getMax()
{
	int idx = 0;
	RFOR(i, 63, 0)
	{
		if(freq[i]&1) continue;
		ll mx = -1;
		int id = idx;
		FOR(j, idx, n)
		{
			if((v[j] & (1LL << i)) > 0 && mx < v[j])
			{
				mx = v[j];
				id = j;
			}
		}
		if(mx == -1) continue;
		swap(v[idx], v[id]);
		FOR(j, 0, n)
		{
			if(idx != j && (v[j] & (1LL << i)) > 0)
				v[j] ^= v[idx];
		}
		idx++;
	}
	ll ans = 0LL;
	FOR(i, 0, n)
	{
		ans ^= v[i];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		ll xr = 0LL;
		FOR(i, 0, n)
		{
			cin >> v[i];
			xr ^= v[i];
		}
		RFOR(i, 63, 0)
		{
			freq[i] = 0;
			FOR(j, 0, n)
			{
				if((v[j] & (1LL << i)) > 0)
					freq[i]++;
			}
		}
		ll mx = getMax();
		printf("%lld\n", mx + (xr^mx));
	}
	return 0;
}
