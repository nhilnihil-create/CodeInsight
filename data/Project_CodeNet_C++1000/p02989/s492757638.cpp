#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int n,p,ans;
	cin >> n;
	vector<int> d(n);
	for (int i = 0;i < n;i++)cin >> d[i];
	sort(d.begin(),d.end());
	p = d[(n-1) / 2];
	if (p == d[n / 2 ])ans = 0;
	else ans = d[n / 2 ] - p;
	cout << ans << endl;
}