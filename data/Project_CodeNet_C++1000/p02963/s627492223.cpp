#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>
#include <list>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;

int main(void)
{
	lli S; cin >> S;
	lli x = S / 1000000000 + 1;
	lli y = 1000000000 - S % 1000000000;
	if (S % 1000000000 == 0) {
		x--;
		y = 0;
	}

	cout << 0 << " " << 0 << " " << 1 << " " << 1000000000 << " " << x << " " << y << " " << endl;


	return 0;
}