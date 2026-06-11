#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void maxHeapify(vector<int>& a, int i, int h)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int largest = i;
	if (1 <= l && l <= h && a[i] < a[l]) largest = l;
	if (1 <= r && r <= h && a[largest] < a[r]) largest = r;

	if (largest != i) {
		swap(a[i], a[largest]);
		maxHeapify(a, largest, h);
	}
}

void buildMaxHeap(vector<int>& a, int h)
{
	for (int i = h / 2; 1 <= i; i--) {
		maxHeapify(a, i, h);
	}
}

int main()
{
	int h;
	cin >> h;
	vector<int> a(h + 1);
	for (int i = 1; i <= h; i++) cin >> a[i];

	buildMaxHeap(a, h);

	for (int i = 1; i <= h; i++) cout << " " << a[i];
	cout << endl;
}
