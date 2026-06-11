#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <functional>
using namespace std;

int main()
{
	//10000までの素数リスト作成
	//与えられた数がその素数リストの数（≦与えられた数の平方根）で割れるかどうか調べる

	bool checked[10001] = {}; //[]内の数字が素数かどうかチェックしたかどうかを示す
	int sosuu[10001];
	int sosuu_cnt = 0;

	checked[0] = true;
	checked[1] = true;
	for (int i = 2; i <= 100; i++)
	{
		if (checked[i] == true)
		{
			continue;
		}
		else
		{
			for (int j = 2; i * j <= 10000; j++)
			{
				checked[i * j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		if (checked[i] == false)
		{
			sosuu[sosuu_cnt] = i;
			sosuu_cnt++;
		}
	}

	int n;
	cin >> n;
	int cnt = 0; //合成数のカウント
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		for (int j = 0; j < sosuu_cnt; j++)
		{
			if (sosuu[j] > sqrt(input))
			{
				break;
			}
			else if (input % sosuu[j] == 0)
			{
				cnt++;
				break;
			}
		}
	}
	cout << n - cnt << endl; 
	return 0;
}