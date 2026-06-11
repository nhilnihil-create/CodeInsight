#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

template <typename T>
struct RollingHash
{
	T& ary;
	int size;
	int n;
	vector<ll> factor;
	ll b = 0;
	ll mod = 0;
	ll hash = 0;
	int index = -1;

	RollingHash(T& _ary, int _size, int _n, ll _b = (ll)1e8 + 7, ll _mod = (ll)1e9 + 7) : ary(_ary)
	{
		size = _size;
		n = _n;
		b = _b;
		mod = _mod;
		auto temp = 1ll;
		for (auto i = 0; i < n; ++i)
		{
			factor.push_back(temp);
			temp = temp * b % mod;
		}
		for (auto i = 0; i < n; ++i)
		{
			hash = (hash + ary[i] * factor[n - i - 1] % mod) % mod;
		}
	}

	bool moveNext() {
		if (index + n >= size)
		{
			return false;
		}
		if (index < 0)
		{
			++index;
			return true;
		}

		hash = (((hash - ary[index] * factor[n - 1]) % mod) + mod) % mod;
		hash = hash * b % mod;
		hash = (hash + ary[index + n]) % mod;
		++index;
		return true;
	}

	ll getHash() { return hash; }
	int getIndex() { return index; }
};

int main()
{
	int N;
	string S;
	cin >> N >> S;

	vector<ll> listB = { (ll)1e5 + 7, (ll)1e8 + 7 };
	int low = 1;
	int high = N;
	while (low <= high)
	{
		auto foundAll = true;
		auto mid = (low + high) / 2;
		for (auto b : listB)
		{
			RollingHash<string> r1(S, N, mid, b);
			RollingHash<string> r2(S, N, mid, b);
			vector<ll> hashList;
			map<ll, int> hashMap;

			while (r1.moveNext() != false)
			{
				if (r1.getIndex() < mid)
				{
					continue;
				}

				hashList.push_back(r1.getHash());
				++hashMap[r1.getHash()];
			}

			auto found = false;
			auto i = 0;
			while (r2.moveNext() != false)
			{
				auto it = hashMap.find(r2.getHash());
				if (it != hashMap.end() && it->second > 0)
				{
					found = true;
					break;
				}

				if (i < (int)hashList.size())
				{
					--hashMap[hashList[i]];
				}
				++i;
			}

			if (!found)
			{
				foundAll = false;
				break;
			}
		}

		if (foundAll)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << high << endl;

	return 0;
}