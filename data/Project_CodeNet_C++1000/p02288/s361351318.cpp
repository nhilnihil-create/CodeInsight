#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
int n;
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }
void maxHeapify(int *p, int i) {
	int l = left(i);
	int r = right(i);
	int lg;
	if (l <= n && p[i] < p[l]) 
			lg = l;
	else lg = i;
	if (r <= n && p[lg] < p[r]) 
		lg = r;
	if (lg != i) {
		swap(p[i], p[lg]);
		maxHeapify(p, lg);
	}
}
int main() {
	cin >> n;
	int *pt;
	pt = new int[n];
	for (int i = 1; i <= n; i++)
		cin >> pt[i];
	for (int i = n/2; i >= 1; i--) maxHeapify(pt, i);
	for (int i = 1; i <= n; i++) cout << " " << pt[i];
	cout << endl;
	return 0;
}