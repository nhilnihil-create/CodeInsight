#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nCnt = 0;

void insertionSort(int nIn[], int nNum, int g)
{
	for (int i = g; i < nNum; ++i)
	{
		int v = nIn[i];
		int j = i - g;
		while (j >= 0 && nIn[j] > v)
		{
			nIn[j + g] = nIn[j];
			j -= g;
			nCnt++;
		}
		nIn[j + g] = v;
	}
}

void shellSort(int nIn[], int nNum)
{
	nCnt = 0;
	vector<int> vecG;
	int nH = 1;
	while (nH <= nNum)
	{
		vecG.push_back(nH);
		nH = nH * 3 + 1;
	}
	cout << vecG.size() << endl;
	for (int i = vecG.size() - 1; i >= 0; --i)
	{
		cout << vecG[i];
		if (i)
		{
			cout << " ";
		}
	}
	cout << endl;
	for (int i = vecG.size() - 1; i >= 0; --i)
	{
		insertionSort(nIn, nNum, vecG[i]);
	}
}

int main()
{
	int nNum = 0;
	cin >> nNum;
	int nIn[1000000] = { 0 };
	for (int i = 0; i < nNum; ++i)
	{
		cin >> nIn[i];
	}
	shellSort(nIn, nNum);

	cout << nCnt << endl;
	for (int i = 0; i < nNum; ++i)
	{
		cout << nIn[i] << endl;
	}
	return 0;
}
