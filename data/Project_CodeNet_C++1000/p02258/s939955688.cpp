#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int n;
int r[200000];
int minv;
int maxv;



int main()
{
	cin >> n;
	for (int i = 0; i <= n - 1; i++) {
		cin >> r[i];
	}
	minv = r[0];
	maxv = r[1]-r[0];
	for (int i = 1; i <= n - 1; i++) {
		if (r[i] - minv > maxv) maxv = r[i] - minv;
		if (r[i] < minv) minv = r[i];
	}
	cout << maxv << endl;
}