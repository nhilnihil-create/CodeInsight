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
#define INT_MIN -2147483646
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

static const int N = 105;

struct vertex {
	int id;
	int p;
	int d;
	bool operator<(const vertex & another) const {
		return (d != another.d ? d>another.d : id>another.id);
	}
};

int main() {
	vvi mx(N, vi(N, -1));
	int n;
	cin >> n;
	Loop(i, n) {
		Loop(j, n) {
			int a;
			cin >> a;
			mx[i][j] = a;
		}
	}
	//
	vi color(N, 0); //0,1,2
	priority_queue<vertex> q;
	q.push({ 0,-1,0});
	int ret = 0;
	while(q.size() > 0) {//?
		vertex v = q.top();
		q.pop();
		if (color[v.id] == 2) continue;
		color[v.id] = 2;
		ret += v.d;
		Loop(j, n) {
			if (mx[v.id][j] != -1 && color[j] != 2){
					q.push({ j, v.id,mx[v.id][j] });
					color[j] = 1;
			}
		}
	}
	cout << ret << endl;
	return 0;
}