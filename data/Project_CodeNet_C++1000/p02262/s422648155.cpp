#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class cShell
{
	int m_n;
	int cnt;
	vector<int> vA;
	vector<int> vg;

	void insertionSort(int g);

public:
	cShell(int n, vector<int> & v)
	{
		vA = v;
		m_n = n;
		cnt = 0;
	}
	
	void shellSort();

	int getm()
	{
		return vg.size();
	}

	string getGapToStr();

	vector<int> getData()
	{
		return vA;
	}

	int getCnt()
	{
		return cnt;
	}
};

void cShell::insertionSort(int g)
{
	for (int i = g; i < m_n; ++i)
	{
		int v = vA[i];
		int j = i - g;
		while (j >= 0 && vA[j] > v)
		{
			vA[j + g] = vA[j];
			j = j - g;
			cnt++;
		}
		vA[j + g] = v;
	}
}

void cShell::shellSort()
{
	int cnt = 0;
	int m = vA.size();
	if (m / 2 > 0)
	{
		while (m /= 2)
		{
			vg.push_back(m);
		}
	}
	else
	{
		vg.push_back(1);
	}
	for (int i = 0; i < vg.size(); ++i)
	{
		insertionSort(vg[i]);
	}
}

string cShell::getGapToStr()
{
	ostringstream oss;
	for (int i = 0; i < vg.size() - 1; ++i)
	{
		oss << vg[i] << " ";
	}
	oss << vg[vg.size() - 1];
	return oss.str();
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	vector<int> va;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		va.push_back(t);
	}

	cShell cs(n, va);
	cs.shellSort();

	cout << cs.getm() << endl;
	cout << cs.getGapToStr() << endl;
	cout << cs.getCnt() << endl;
	va = cs.getData();
	for (int i = 0; i < va.size(); ++i)
	{
		cout << va[i] << endl;
	}

	return 0;
}