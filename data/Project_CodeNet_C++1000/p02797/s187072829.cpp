#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, K, S; cin >> N >> K >> S;
	vector<ll> res;
	for (ll i = 0; i < K; ++i)
		res.push_back(S);
	ll t;
	if (S == 1000000000)
		t = 1000000000-1;
	else
		t = 1000000000;
	
	for (ll i = K; i < N; ++i)
		res.push_back(t);
	for (auto e : res)
		std::cout << e << " ";
}