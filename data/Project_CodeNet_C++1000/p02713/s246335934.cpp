#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int gcd(int a, int b, int c) { return gcd(a, gcd(b, c)); }

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k; cin >> k;
	int sum{ 0 };
	for (int a = 1; a <= k; a++)
	{
		for (int b = 1; b <= k; b++)
		{
			for (int c = 1; c <= k; c++)
			{
				sum += gcd(a, b, c);
			}
		}
	}

	cout << sum << '\n';
}