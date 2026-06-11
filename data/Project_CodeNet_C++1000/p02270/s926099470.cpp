#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int MAXW = 10000;
int n, k, weight[MAXN];
int getloadedNum(int P)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		int temp = 0;
		while (temp + weight[num] <= P)
		{
			temp += weight[num];
			num++;
			if (num == n)
				return n;
		}
	}
	return num;
}
int solve()
{
	int left = 0;
	int right = MAXN * MAXW;
	while (left+1<right)
	{
		int mid = (left + right)/2;
		int maxNum = getloadedNum(mid);
		if (maxNum >= n)
			right = mid;
		else
			left = mid;
	}
	return right;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	cout << solve() << endl;
}
