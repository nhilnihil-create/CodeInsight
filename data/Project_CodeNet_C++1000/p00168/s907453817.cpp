#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <sstream>
using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long

int n;
int step[35];

int main()
{
	step[0] = 0;
	step[1] = 1;
	step[2] = 2;
	step[3] = 4;
	FOR(i, 1, 30)
	{
		step[i + 3] = step[i + 2] + step[i + 1] + step[i];
	}
	while (1)
	{
		cin >> n; if (n == 0) return 0;
		if (step[n] % 3650 == 0) cout << step[n] / 3650 << endl;
		else cout << step[n] / 3650 + 1 << endl;
	}

}