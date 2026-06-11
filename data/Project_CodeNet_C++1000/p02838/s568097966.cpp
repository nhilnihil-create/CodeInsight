#ifdef _WIN32
#include "XOR.h"
#endif

#include <stdio.h>

#include <iostream>
#include <vector>
#include <array>

constexpr int64_t MOD = 1'000'000'007;
constexpr int64_t help = 1;

#define ll long long int

void fastscan(ll& number) {
	//variable to indicate sign of input number 
	int c;

	number = 0;

	// extract current character from buffer 
	c = getchar();

	// Keep on extracting characters if they are integers 
	// i.e ASCII Value lies from '0'(48) to '9' (57) 
	for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;

	// if scanned input has a negative sign, negate the 
	// value of the input number 
}
#ifdef _WIN32
namespace XOR
{
#endif 

	int main() {
		ll n;

		fastscan(n);


		std::array<ll, 62> bits{};
		for (ll i = 0; i < n; i++) {
			ll d;
			fastscan(d);
			for (ll b = 0; b < 62; b++) {
				bits[b] += !!(d & (help << b));
			}
		}

		ll ans = 0;

		for (ll b = 0; b < 62; b++) {
			ll p = (help << b) % MOD;
			ans += (bits[b] * (n - bits[b]) % MOD) * p;
			ans %= MOD;
		}

		std::cout << ans;
	}
#ifdef _WIN32
}
#endif 
