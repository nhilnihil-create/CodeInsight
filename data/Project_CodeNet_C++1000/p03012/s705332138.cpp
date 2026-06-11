#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef unsigned long long int ll;



int main()
{
	int n;
	cin >> n;
	int *w = new int[n];
	rep(i, n) cin >> w[i];
	int s1;
	int s2;
	int ans = 10000;
	for (int i = 1; i < n; i++) {
		s1 = 0;
		s2 = 0;
		for (int left = 0; left < i; left++) {
			s1 += w[left];
		}
		for (int right = i; right < n; right++) {
			s2 += w[right];
		}
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << endl;
	return 0;
}