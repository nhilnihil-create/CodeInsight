#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;

typedef struct union_find_tree {
	vector<int> data;
	map<int, int> parent;
	map<int, int> rank;

	//constructor
	union_find_tree(vector<int> data_) {
		data = data_;
		
		for (int i=0; i<(int)data.size(); i++) {
			parent[data[i]] = data[i];
			rank[data[i]] = 1;
		}
	}

	//Find root
	int root (int x) {
		return parent[x] == x ? x : parent[x] = root(parent[x]);
	}

	//check if the two emements are in the same tree
	bool is_same(int x, int y) {
		return root(x) == root(y);
	}	
	
	//Unite two trees
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		
		if (x == y) return;

		if (rank[x] < rank[y])
			parent[x] = y;
		else {
			parent[y] = x;
			if (rank[x] == rank[y]) rank[x]++; 
		}
		return;
	}
} uft;

int n, q;

int main() {
  int i;
  scanf("%d%d ", &n, &q);

  vector<int> data(n);
  for (i=0; i<n; i++) data[i] = i;
  uft u(data);

  for (i=0; i<q; i++) {
    int c, x, y;
    scanf("%d%d%d ", &c, &x, &y);
    if (c==0)
      u.unite(x, y);
    else {
      printf("%d\n", (u.is_same(x,y)) ? 1 : 0);  
    }
  }

	return 0;
}