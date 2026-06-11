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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265358979

using namespace std;
typedef pair<int, int> P;

int main(void) {
	int n;
	while (cin >> n, n) {
		int s[1001];
		double alpha=0, ave = 0;
		FOR(i, 1, n) {
			cin >> s[i];
			ave += s[i];
		}
		ave /= n;
		FOR(i, 1, n) {
			alpha += (s[i] - ave)*(s[i] - ave);
		}
		alpha /= n;
		alpha = sqrt(alpha);
		printf("%.10lf\n", alpha);
	}
	return 0;
}
