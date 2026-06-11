#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	string str;
	ll k;
	cin >> str >> k;

	bool flag{true};
	for (ll i = 1; i < (ll)str.size(); ++i)
	{
		flag &= (str[i-1] == str[i]);
	}

	if (flag)
	{
		std::cout << (str.size() * k) / 2ll << std::endl;
	}
	else if (str.front() != str.back())
	{
		ll res{0};
		for (ll i = 0; i < (ll)str.size();)
		{
			ll j = i + 1;
			while (j < (ll)str.size() && str[i] == str[j]) {++j;}
			res += (j - i) / 2ll;
			i = j;
		}
		std::cout << res * k << std::endl;
	}
	else
	{
		ll l{0}, r{(ll)str.size()-1};
		char f = str.front();
		char b = str.back();
		
		while (l < (ll)str.size() && f == str[l]) {++l;};
		while (r >= 0 && b == str[r]) {--r;}

		// std::cout << "l : " << l << std::endl;
		// std::cout << "r : " << r << std::endl;

		ll res{0};
		for (ll i = l; i <= r;)
		{
			ll j = i + 1;
			while (j < (ll)str.size() && str[i] == str[j]) {++j;}
			res += (j - i) / 2;
			// std::cout << (j-i)/2 << std::endl;
			i = j;
		}

		// std::cout << "left : " << l << std::endl;
		// std::cout << "right : " << str.size()-r-1 << std::endl;
		res *= k;
		ll tmp = (l + str.size()-r-1) / 2;
		res += tmp * (k-1);
		res += l/2;
		res += (str.size()-r-1) / 2;
		std::cout << res << std::endl;
	}
}
