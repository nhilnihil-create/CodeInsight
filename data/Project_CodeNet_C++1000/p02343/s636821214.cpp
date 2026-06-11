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

class cDisjointSet
{
	vector<int> vp;
	vector<int> vrank;
public:
	cDisjointSet(int n);
	void makeSet(int x);
	void uunionn(int x, int y);
	int findSet(int x);
	bool isSameSet(int x, int y);
	void link(int x, int y);
};

cDisjointSet::cDisjointSet(int n)
{
	vp.resize(n);
	vrank.resize(n);
	for (int i = 0; i < n; ++i)
		makeSet(i);
}
void cDisjointSet::makeSet(int x)
{
	vp[x] = x;
	vrank[x] = 0;
}

void cDisjointSet::uunionn(int x,int y)
{
	link(findSet(x), findSet(y));
}

int cDisjointSet::findSet(int x)
{
	if(x!=vp[x])
		vp[x] = findSet(vp[x]);
	return vp[x];
}

bool cDisjointSet::isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

void cDisjointSet::link(int x, int y)
{
	if (vrank[x] > vrank[y])
		vp[y] = x;
	else
	{
		vp[x] = y;
		if (vrank[x] == vrank[y])
			vrank[y]++;
	}
}

int main()
{
	////ifstream fin("DPL_1_C-in40.txt");
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
	cDisjointSet cd(n);

	for (int i = 0; i < q; ++i)
	{
		cin >> com >> x >> y;
		//fin >> com >> x >> y;
		switch(com)
		{
		case 0:
			cd.uunionn(x, y);
			break;
		case 1:
			cout << (cd.isSameSet(x, y) ? 1 : 0) << endl;
		}
	}
	return 0;
}