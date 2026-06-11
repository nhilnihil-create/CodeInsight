#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;
//#define DEBUG(x) ;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

vector<long long> toDivisor(ll num)
{
	vector<long long> d;
	for (ll i = 1; i*i <= num; ++i)
	{
		if (i*i == num)
		{
			d.push_back(i);
		}
		else if (num % i == 0)
		{
			d.push_back(i);
			d.push_back(num/i);
		}
	}
	return d;
}

vector<pair<long long , long long>> toDivisorP(ll num)
{
	vector<pair<long long, long long>> d;
	for (ll i = 1; i * i <= num; ++i)
	{
		if (i*i == num) d.push_back(pair<ll, ll>(i, i));
		else if (num % i == 0)
		{
			d.push_back(pair<ll, ll>(i, num/i));
		}
	}
	return d;
}


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N; cin >> N;
	vector<ll> d1 = toDivisor(N-1);
	vector<ll> d2 = toDivisor(N);

	ll res{d1.size()-1};

	for (auto e : d2)
	{
		if (e == 1) continue;

		ll nc = N;
		while (nc > 0)
		{
			if (nc % e != 0)
			{
				if (nc % e == 1)
				{
					++res;
				}
				break;
			}
			nc /= e;
		}
	}

	std::cout << res << std::endl; 
	
	return 0;
}
