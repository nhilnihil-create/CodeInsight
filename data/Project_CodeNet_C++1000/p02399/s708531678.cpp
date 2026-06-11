#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include<cstdio>
#include <vector>
#include<queue>
#include<limits.h>
#include<string.h>
#include<functional>
using namespace std;

signed main() {
	int a, b; cin >> a >> b;
	printf("%d %d %.10lf\n", a / b, a%b, double(a) / b);
}