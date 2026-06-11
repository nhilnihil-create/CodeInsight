#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	/*int n, r;
	cin >> n >> r;
	if (n >= 10)
		cout << r;
	else
		cout << r + (10 - n) * 100;*/

	//long long n, k = 0;
	//cin >> n >> k;
	//int ans = 1;
	//while (n >= k)
	//{
	//	n /= k;
	//	ans += 1;
	//}
	//cout << ans;

	int n;
	cin >> n;
	int dog[101];
	float key = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> dog[i];
		key += dog[i];
	}
	key =key/n;
	int point = key;
	if (key - point > 0.5)point++;
	long long ans=0;
	for (int i = 0; i < n; i++)
	{
		ans += pow(dog[i] - point, 2);
	}
	cout << ans;
}
