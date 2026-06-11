#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

char F[2010][2010];

int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	REP(h, H)REP(w, W) cin >> F[h][w];
	vector<vector<ll>> C_ob(W), R_ob(H);

	REP(h, H) R_ob[h].push_back(-1);
	REP(w, W) C_ob[w].push_back(-1);

	REP(h, H)REP(w, W)
	{
		
		if (F[h][w] == '#')
		{
			C_ob[w].push_back(h);
			R_ob[h].push_back(w);
		}
	}

	REP(h, H) R_ob[h].push_back(W);
	REP(w, W) C_ob[w].push_back(H);

	ll res{0};
	REP(h, H)REP(w, W)
	{
		if (F[h][w] == '#') continue;

		ll top, down, left, right;
		top = *(lower_bound(C_ob[w].begin(), C_ob[w].end(), h)-1) + 1;
		down = *lower_bound(C_ob[w].begin(), C_ob[w].end(), h) - 1;
		
		left = *(lower_bound(R_ob[h].begin(), R_ob[h].end(), w)-1) + 1;
		right = *lower_bound(R_ob[h].begin(), R_ob[h].end(), w) - 1;

		// std::cout << "----------"<< std::endl;
		// std::cout << "h, w : " << h << ", " << w << std::endl;
		// std::cout << "top : " << top << std::endl;
		// std::cout << "down : " << down << std::endl;
		// std::cout << "left : " << left << std::endl;
		//std::cout << "right : " << right << std::endl;
		
		res = max(res, right - left + down - top + 1);
	}

	std::cout << res << std::endl;
}
