#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

char F[2010][2010];
ll L[2010][2010];
ll R[2010][2010];
ll U[2010][2010];
ll D[2010][2010];

int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	REP(h, H)REP(w, W) cin >> F[h][w];

	REP(h, H)
	{
		REP(w, W)
		{
			if (F[h][w] == '#')
				L[h][w] = 0;
			else
			{
				if (w == 0)
					L[h][w] = 1;
				else
					L[h][w] = L[h][w-1] + 1;
			}
		}

		for (ll w = W-1; w >= 0; --w)
		{
			if (F[h][w] == '#')
				R[h][w] = 0;
			else
			{
				if (w == W-1)
					R[h][w] = 1;
				else
					R[h][w] = R[h][w+1] + 1;
			}
		}
	}

	REP(w, W)
	{
		REP(h, H)
		{
			if (F[h][w] == '#')
				U[h][w] = 0;
			else
			{
				if (h == 0)
					U[h][w] = 1;
				else
					U[h][w] = U[h-1][w] + 1;
			}
		}

		for (ll h = H-1; h >= 0; --h)
		{
			if (F[h][w] == '#')
				D[h][w] = 0;
			else
			{
				if (h == H-1)
					D[h][w] = 1;
				else
					D[h][w] = D[h+1][w] + 1;
			}
		}
	}

	ll res{0};
	REP(h, H)REP(w, W)
	{
		res = max(res, U[h][w] + D[h][w] + R[h][w] + L[h][w] - 3);
	}

	std::cout << res << std::endl;
}
