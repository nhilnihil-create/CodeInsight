#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <stack>
#include <queue>

#define INT_MAX 2147483647
#define INT_MIN -2147483647

#define NUM 100005
#define INVALID_IDX -1
using namespace std;

struct TreeNode
{
	int p, l, r;
};

TreeNode t[NUM];
int D[NUM];

void print(int idx)
{
	cout << "node " << idx << ": ";
	cout << "parent = " << t[idx].p << ", ";
	cout << "depth = " << D[idx] << ", ";

	if (t[idx].p == INVALID_IDX) cout << "root, ";
	else if (t[idx].l == INVALID_IDX) cout << "leaf, ";
	else cout << "internal node, ";

	cout << "[";
	for (int i = t[idx].l; i != INVALID_IDX; i = t[i].r)
	{
		cout << i;
		if (t[i].r != INVALID_IDX) cout << ", ";
	}
	cout << "]" << endl;
}

void getHeight(int idx, int depth)
{
	D[idx] = depth;
	if (t[idx].r != INVALID_IDX) getHeight(t[idx].r, depth);
	if (t[idx].l != INVALID_IDX) getHeight(t[idx].l, depth + 1);
}

int main()
{
	int i, j, n, idx0, idx1, d, l, r = INVALID_IDX;

	cin >> n;
	for (int i = 0; i < n; ++i) t[i].p = t[i].l = t[i].r = INVALID_IDX;

	for (int i = 0; i < n; ++i)
	{
		cin >> idx0 >> d;
		for (int j = 0; j < d; ++j)
		{
			cin >> idx1;
			if (0 == j) t[idx0].l = idx1;
			else t[l].r = idx1;
			l = idx1;
			t[idx1].p = idx0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (t[i].p == INVALID_IDX){
			r = i;
			break;
		}
	}

	getHeight(r, 0);
	for (int i = 0; i < n; ++i) print(i);

	return 0;
}