#include <iostream>
#include <string>
//#include <cstring>
//#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <stack>
//#include <queue>
//#include <chrono>
//#include <numeric>
//#include <set>
//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <math.h>
//#include <iomanip>
//#include <list>
//#include <limits>

using namespace std;
const int infty = static_cast <int> (pow(256, sizeof(int)) / 2 - 1);

class cRSQ
{
	int m_n;
	vector<int> va;

public:
	cRSQ(int n);
	void add(int i, int x);
	int getSum(int s, int t);

};

cRSQ::cRSQ(int n)
{
	m_n = n + 1;
	va.resize(m_n);
}

void cRSQ::add(int i, int x)
{
	while(i < m_n)
	{
		va[i] += x;
		i += i & -i;
	}

}

int cRSQ::getSum(int s, int t)
{
	int ss = 0 , st = 0;
	s--;
	while(s > 0)
	{
		ss += va[s];
		s -= s & -s;
	}
	while(t > 0)
	{
		st += va[t];
		t -= t & -t;
	}
	return st - ss;
}

int main()
{
	////ifstream fin("DSL_2_A_in3.txt");
	//ifstream fin("test.txt");
	//if (!fin.is_open())
	//{
	//	cout << "File not found." << endl;
	//	return 0;
	//}

	//fin.tie(0);
	//ios::sync_with_stdio(false);

	//int n,q;
	//fin >> n >> q;
	//fin.ignore();

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	cin.ignore();

	int com, x, y;
	cRSQ cr(n);

	for (int i = 0; i < q; ++i)
	{
		cin >> com >> x >> y;
		//fin >> com >> x >> y;
		switch (com)
		{
		case 0:
			cr.add(x, y);
			break;
		case 1:
			cout << cr.getSum(x, y) << endl;
		}
	}
	return 0;
}