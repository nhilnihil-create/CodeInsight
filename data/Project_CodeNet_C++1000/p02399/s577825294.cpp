#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define rep(i,a,n) for(int (i)=a;(i)<(int)(n);(i)++)
#define rrep(i,a,n) for(int (i)=(n)-1;(i)>=a;(i)--)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

int main() {
	int a,b;
	int d,r;
	double f;

	cin >> a >> b;

	d = a / b;
	r = a % b;
	f = (double) a / b;

	printf("%d %d %0.6f\n", d, r, f);
}