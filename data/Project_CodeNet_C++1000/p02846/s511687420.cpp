//#include "stdafx.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <assert.h>
#include <functional>
#include <unordered_map>
#include <cstdint>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef unsigned long long		SQWORD;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
int main()
{
	int T[2];
	cin >> T[0] >> T[1];

	ll speed[2][2];
	cin >> speed[0][0] >> speed[0][1];
	cin >> speed[1][0] >> speed[1][1];

	ll oneDist[2];
	REP(i, 2) {
		oneDist[i]  = speed[i][0] * T[0];
		oneDist[i] += speed[i][1] * T[1];
	}

	if (oneDist[0] == oneDist[1]) {
		cout << "infinity" << endl;
		return 0;
	}

	ll diffDist;
	ll diffKyori;
	ll ans = 0;
	if (oneDist[0] < oneDist[1]) {
		diffDist = oneDist[1] - oneDist[0];
		diffKyori = (speed[0][0] - speed[1][0]) * T[0];
	} else {
		diffDist = oneDist[0] - oneDist[1];
		diffKyori = (speed[1][0] - speed[0][0]) * T[0];
	}

	if (0 < diffKyori) {
		ans = 2 * (diffKyori / diffDist);
		ll amari = diffKyori % diffDist;
		if (0 < amari) ans++;
	}

	cout << ans << endl;
	return 0;
}
