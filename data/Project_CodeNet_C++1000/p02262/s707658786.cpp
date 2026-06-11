#include <iostream>
#include <vector>

using namespace std;

long long cnt;

vector<int> A;
vector<int> G;

void InsertionSort(int n, int g)
{
	for (int i = g;i < n;i++)
	{
		int v = A[i];

		int j = i - g;
		while (j >= 0 && A[j] > v)
		{
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void ShellSort(int n)
{
	// ??°???G(0) = 1, G(n + 1) = 3G(n) + 1
	int h = 1;
	while (h <= n)
	{
		G.push_back(h);
		h = 3 * h + 1;
	}

	// ????????§??????
	for (int i = G.size() - 1;i >= 0;i--)
		InsertionSort(n, G[i]);
}

int main()
{
	int n;
	cnt = 0;

	// ??\???
	cin >> n;

	A.resize(n);
	for (int i = 0;i < n;i++)
		cin >> A[i];

	// ?????§????????????
	ShellSort(n);

	// ??????
	// ??´??°m
	cout << G.size() << endl;

	// G???????´?(?????¨???)
	for (int i = G.size() - 1;i >= 0;i--)
	{
		if (i != G.size() - 1)
			cout << " ";
		cout << G[i];
	}
	cout << endl;

	// ????????????
	cout << cnt << endl;

	// ?????????????????°???
	for (int i = 0;i < n;i++)
		cout << A[i] << endl;

	return 0;
}