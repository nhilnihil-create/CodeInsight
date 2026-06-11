#include <bits/stdc++.h>
#define MAX 200010
#define MOD 1000000007
using namespace std;

char str[MAX];
int arr[MAX];

int prod(int a, int b)
{
	return 1LL * a * b % MOD;
}

int main(void)
{
	int N;
	cin >> N;
	cin >> str;
	int cur = 1;
	int ans = 1;
	for (int i = 1; i < 2 * N; i++)
	{
		if (str[i] == str[i - 1]) arr[i] = !arr[i - 1];
		else arr[i] = arr[i - 1];
		if (arr[i]) ans = prod(ans, cur--);
		else cur++;
	}
	if (cur || str[0] == 'W') ans = 0;
	for (int i = 1; i <= N; i++) ans = prod(ans, i);
	cout << ans << endl;
	return 0;
}
