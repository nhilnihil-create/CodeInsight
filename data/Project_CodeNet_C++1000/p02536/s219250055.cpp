#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int myfind(int a, vector<int>& relation) {
    if (relation[a] == a) return a;
    int res = myfind(relation[a], relation);
    relation[a] = res;
    return res;
}

void myunion(int a, int b, vector<int>& relation) {
    int ta = myfind(a, relation);
    int tb = myfind(b, relation);
    if (ta == tb) return;
    relation[ta] = tb;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> relation(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		relation[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		myunion(a, b, relation);
	}
	unordered_set<int> us;
	for (int i = 1; i <= n; i++) {
		us.insert(myfind(i, relation));
	}
	cout << us.size() - 1 << endl;
}




