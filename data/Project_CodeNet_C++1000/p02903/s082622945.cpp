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
	int H, W, A, B;  cin >> H >> W >> A >> B;
	string X(A, '1'), Y(A, '0');
	rep(i, 0, W - A) {
		X.push_back('0');
		Y.push_back('1');
	}

	rep(i, 0, B)cout << X << endl;
	rep(i, 0, H - B)cout << Y << endl;

	return 0;
}
