#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <tuple>
#include <functional>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <map>
#include <random>
#include <cstdlib>
#define INT_MAX 2147483647
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i < (int)n; i++)
#define Loopr(i, n) for(int i= (int)n - 1; i >= 0; i--)
using namespace std;
typedef long long int ll;

struct node {
	int parent, left, right;
};

int n;
vector<node> nodes(100000, { -1,-1,-1 });

int depth(int id) {
	if (nodes[id].parent == -1) return 0;
	else return depth(nodes[id].parent) + 1; 
}

void print(int id) {
	int d;
	string t;
	d = depth(id);
	int buf = nodes[id].left;
	if (d == 0) t = "root";
	else if (buf == -1) t = "leaf";
	else t = "internal node";
	cout << "node " << id << ": parent = "<< nodes[id].parent
		<<", depth = " << d << ", " << t << ", [";
	if (buf != -1) {
		cout << buf;
		while (nodes[buf].right != -1) {
			cout << ", " << nodes[buf].right;
			buf = nodes[buf].right;
		}
	}
	cout << "]" << endl;
}

int main() {
	cin >> n;
	Loop(i, n) {
		int id, dim, buf, buf2;
		cin >> id >> dim;
		Loop(j, dim) {
			if (j == 0) {
				cin >> buf;
				nodes[id].left = buf;
			}
			else {
				cin >> buf2;
				nodes[buf].right = buf2;
				buf = buf2;
			}
			nodes[buf].parent = id;
		}
	}
	Loop(i, n) print(i);
	return 0;
}