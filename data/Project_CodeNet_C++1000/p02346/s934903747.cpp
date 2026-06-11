#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct query {
	int x;
	int y;
	query(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator< (const query& r) const {
		return this->x < r.x;
	}
	bool operator< (const int& r) const {
		return this->x < r;
	}
};
bool operator< (const int& l, const query& r) {
	return l < r.x;
}

struct node {
	int begin;
	int end;
	int sum = 0;
	node* child1;
	node* child2;
	vector<query> queries;
	node(int begin, int end) {
		this->begin = begin;
		this->end = end;
	}
};


node* root;

node* init(int begin, int end) {
	node* parent = new node(begin, end);
	if (begin != end) {
		int mid = (begin + end) / 2;
		parent->child1 = init(begin, mid);
		parent->child2 = init(mid + 1, end);
	}
	return parent;
}

void add(node* nod, int x, int y) {
	nod->queries.push_back(query{ x, y });
	//node* nod = root;
	//while (nod->begin != nod->end) {
	//	nod->sum += y;
	//	if (x <= nod->child1->end)
	//		nod = nod->child1;
	//	else
	//		nod = nod->child2;
	//}
	//nod->sum += y;
}

int getSum(node* nod, int x, int y) {
	if (nod->end < x)
		return 0;
	if (nod->begin > y)
		return 0;
	
	if (nod->begin == nod->end) {
		for (auto it : nod->queries) {
			nod->sum += it.y;
		}
		nod->queries.clear();
		return nod->sum;
	}

	sort(begin(nod->queries), end(nod->queries));
	auto separator = upper_bound(begin(nod->queries), end(nod->queries), nod->child1->end);
	for (auto it = begin(nod->queries); it != separator; ++it) {
		add(nod->child1, it->x, it->y);
		nod->sum += it->y;
	}
	for (auto it = separator; it != end(nod->queries); ++it) {
		add(nod->child2, it->x, it->y);
		nod->sum += it->y;
	}
	nod->queries.clear();

	if (nod->begin == x && y == nod->end)
		return nod->sum;
	return getSum(nod->child1, x, min(y,nod->child1->end)) + getSum(nod->child2, max(nod->child2->begin,x), y);	
}

int main() {
	int n, q;
	cin >> n >> q;
	root = init(1, n);
	for (int i = 0; i < q; ++i) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0)
			add(root, x, y);
		else
			cout << getSum(root,x, y) << endl;
	}
}