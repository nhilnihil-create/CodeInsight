#include<iostream>

#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
bool black[SIZE];

int main() {
	
	int n;
	cin >> n >> str;

	for (int i = 0; i < 2 * n; i++)
	{
		// 奇数番目
		if (i % 2)
		{
			black[i] = str[i] == 'B';
		}
		// 偶数番目
		else
		{
			black[i] = str[i] == 'W';
		}
	}
	ll ret = 1;
	int stack = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		// white
		if (black[i] == false)
		{
			stack++;
			//cout << stack << endl;
		}
		// black
		else
		{
			// 組み合わせなし
			if (stack == 0)
			{
				cout << 0;
				return 0;
			}
			ret = ret * (ll)stack % MOD;
			stack--;
			//cout << stack << " : " << ret << endl;
		}
	}
	if (stack > 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ret = ret * (ll)i % MOD;
	}
	cout << ret;
	return 0;
}