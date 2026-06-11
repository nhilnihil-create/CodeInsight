#include <iostream>
#include <stdlib.h>
using namespace std;

void DFS(int* arr, int pos, int* res, int index, bool& flag) {
	if (pos >= 10||flag)
	{
		return;
	}
	if ((index==0) || (index >= 1 && res[index - 1] < arr[pos]))
	{
		res[index] = arr[pos];
		arr[pos] = 0;
	}
	DFS(arr, pos+1, res, index+1, flag);
	if (flag)
	{
		return;
	}
	int pre = 0;
	int cur = 0;
	flag = true;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]!=0)
		{
			pre = pre == 0 ? arr[i] : cur;
			cur = arr[i];
			if (cur < pre)
			{
				flag = false;
				break;
			}
		}
	}
}

int main()
{
	int N, arr[11], res[10];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[j];
		}
		bool flag = false;
		DFS(arr, 0, res, 0, flag);
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}