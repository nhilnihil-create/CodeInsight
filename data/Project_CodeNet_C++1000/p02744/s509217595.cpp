#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N;

void bfs(string s, char mc)
{
	if (N == s.size())
	{
		std::cout << s << std::endl;
		return;
	}

	for (char c = 'a'; c <= mc+1; ++c)
	{
		bfs(s + c, max(c, mc));
	}
}

int main(int argc, char **argv)
{
	cin >> N;
	bfs("a", 'a');
}