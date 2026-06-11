#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> par;
vector<int> t_rank;

void init_union_find(void) {
	par.resize(N + 1, 0);
	t_rank.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		par[i] = i;
}

int find(int x) {
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (t_rank[x] < t_rank[y])
		par[x] = y;
	else {
		par[y] = x;
		if (t_rank[x] == t_rank[y])
			t_rank[x]++;
	}
}

void input_init(void) {
	cin >> N >> M;
	init_union_find();
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		unite(a, b);
	}
}

int get_group_cnt(void) {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (par[i] == i)
			++cnt;
	}
	return cnt;
}

int main(void) {
	input_init();
	int g_cnt = get_group_cnt();
	int ans = g_cnt - 1;
	cout << ans << '\n';
	return 0;
}
