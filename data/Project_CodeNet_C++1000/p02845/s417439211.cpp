#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int hat[100010] = { 0 }, co[100010] = { 0 };
long long ans = 1;
int main(){
	int n;
	int a[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	hat[0] = 3;
	for (int j = 0; j < n; j++) {
		ans = ans * (hat[a[j]] - co[a[j]]) % 1000000007;
		hat[a[j] + 1]++;
		co[a[j]]++;
	}
	cout << ans << endl;
}