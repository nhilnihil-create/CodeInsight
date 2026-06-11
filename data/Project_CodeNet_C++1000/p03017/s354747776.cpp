#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;;
	--A, --B, --C, --D;
	string S; cin >> S;

	for (ll i = min(A, B)+1; i < (max(C, D)-1); ++i)
	{
		if ((S[i] == S[i+1]) && (S[i] == '#'))
		{
			std::cout << "No"<< std::endl;
			return 0;
		}
	}

	if (C < D)
	{
		std::cout << "Yes" << std::endl;
		return 0;
	}
	else
	{
		for (ll i = B-1; i < D+2-3+1; ++i )
		{
			if (S[i] == '.' && S[i+1] == '.' && S[i+2] == '.')
			{
				std::cout << "Yes"<< std::endl;
				return 0;
			}
		}
		std::cout << "No"<< std::endl;
	}
}
