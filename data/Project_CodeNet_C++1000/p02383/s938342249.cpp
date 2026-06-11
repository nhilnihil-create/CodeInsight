#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair<long long int, long long int> P;

int main(void) {
	struct Dice {
		int suf[7];
	};

	string s;
	Dice d1;
	int tmp;

	FOR(i, 1, 6) {
		cin >> d1.suf[i];
	}
	cin >> s;

	FOR(i, 0, s.size() - 1) {
		switch (s[i]) {
		case 'N':
			tmp = d1.suf[1];
			d1.suf[1] = d1.suf[2];
			d1.suf[2] = d1.suf[6];
			d1.suf[6] = d1.suf[5];
			d1.suf[5] = tmp;
			break;
		case 'E':
			tmp = d1.suf[1];
			d1.suf[1] = d1.suf[4];
			d1.suf[4] = d1.suf[6];
			d1.suf[6] = d1.suf[3];
			d1.suf[3] = tmp;
			break;
		case 'W':
			tmp = d1.suf[1];
			d1.suf[1] = d1.suf[3];
			d1.suf[3] = d1.suf[6];
			d1.suf[6] = d1.suf[4];
			d1.suf[4] = tmp;
			break;
		case 'S':
			tmp = d1.suf[1];
			d1.suf[1] = d1.suf[5];
			d1.suf[5] = d1.suf[6];
			d1.suf[6] = d1.suf[2];
			d1.suf[2] = tmp;
			break;
		}
	}
	cout << d1.suf[1] << endl;
	return 0;
}
