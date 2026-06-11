#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

int main() {
	cout << fixed << setprecision(8);
	int a, b, C; cin >> a >> b >> C;
	double rad = acos(-1)*C / 180,
		S = a*b*sin(rad) / 2,
		L = a + b + sqrt(a*a + b*b - 2 * a*b*cos(rad)),
		h = S * 2 / a;
	cout << S << endl;
	cout << L << endl;
	cout << h << endl;
		return 0;
}