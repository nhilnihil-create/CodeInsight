#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.rbegin(), a.rend());

	if (a[m - 1] >= ((double)sum / (4 * m)))cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}




//AAAAAAAAAAAAAAAAAAA
//int main() {
//	int x, y, z;
//	cin >> x >> y >> z;
//
//	cout << z << " " << x << " " << y << endl;
//
//
//	return 0;
//}