#include <bits/stdc++.h>
#define INF 2000000001
#define MAX 502
using namespace std;

int main()
{
	int H;
	int heap[MAX];
	cin >> H;
	for (int i = 0; i < MAX; i++) {
		if (i >= 1 && i <= H)
			cin >> heap[i];
		else
			heap[i] = INF;
	}
	for (int i = 1; i <= H; i++) {
		cout << "node " << i << ": ";
		cout << "key = " << heap[i] << ", ";
		if (heap[i / 2] != INF)
			cout << "parent key = " << heap[i / 2] << ", ";
		if (heap[i * 2] != INF)
			cout << "left key = " << heap[i * 2] << ", ";
		if (heap[i * 2 + 1] != INF)
			cout << "right key = " << heap[i * 2 + 1] << ", ";
		cout << endl;
	}
	return 0;
}