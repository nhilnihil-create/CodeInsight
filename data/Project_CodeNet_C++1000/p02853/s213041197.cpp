#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

int a, b = 0, n, k;
string s, t;
//cout<<<<endl;


int main()
{
	int x, y;
	cin >> x >> y;
	int sum = 0;
	if (x < 4)
		sum += (4 - x) * 100000;
	if (y < 4)
		sum += (4 - y) * 100000;
	if (x == 1 && y == 1)
		sum += 400000;
	cout << sum << endl;
}
