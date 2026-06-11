#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long  ll;

int main()
{
	ll N, K, S;
	cin >> N >> K >> S;
	if (S < 1000000000)
	{
		for (ll i = 0; i < K; i++)
		{
			if (i == 0) {
				cout << S;
				continue;
			}
			cout << " " << S;
		}
		for (ll i = K; i < N; i++)
		{
			cout << " " << S + 1;
		}
	}
	else
	{
		for (ll i = 0; i < K; i++)
		{
			if (i == 0) {
				cout << S;
				continue;
			}
			cout << " " << S;
		}
		for (ll i = K; i < N; i++)
		{
			cout <<" " << 1;
		}
	}
	cout << endl;
	return 0;
}