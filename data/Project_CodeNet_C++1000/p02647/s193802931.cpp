#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T> struct dual_segment_tree {
	using F = function<T(T, T)>;
	using value_type = T;
private : 
	int n, hight;
	const F f;
	const value_type ie;
	vector<value_type> node;

public : 
	dual_segment_tree (const F &f, const value_type &ie) : f(f), ie(ie) { }
	
	void resize (int _n) {
		n = 1; hight = 0;
		while (n < _n) { n <<= 1; hight++; }
		node.resize(2 * n);
		fill(node.begin(), node.end(), ie);
	}

	void resize (int _n, const value_type &e) {
		n = 1; hight = 0;
		while (n < _n) { n <<= 1; hight++; }
		node.resize(2 * n);
		fill(node.begin(), node.end(), ie);
		for (int i = n; i < 2 * n; i++) node[i] = e;
	}
	
	template<class iter>
	void build (iter l, iter r) {
		resize(r - l);
		for (int i = n; l != r; i++, l++) node[i] = (*l);
	}

	void propagate (int i) {
		if (node[i] == ie) return;
		node[i << 1 | 0] = f(node[i << 1 | 0], node[i]);
		node[i << 1 | 1] = f(node[i << 1 | 1], node[i]);
		node[i] = ie;
	}

	inline void apply (int i) {
		for (int j = hight; j > 0; j--) propagate(i >> j);
	}

	void update (int a, int b, const value_type &x) {
		apply(a + n); apply(b + n - 1);
		for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) { node[l] = f(node[l], x); l++; }
			if (r & 1) { r--; node[r] = f(node[r], x); }
		}
	}

	const value_type &operator[] (int i) {
		apply(i + n);
		return node[i + n];
	}

	void swap (dual_segment_tree &s) {
		(this->node).swap(s.node);
	}

};


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	
	auto f = [](int a, int b) { return (a + b); };
	dual_segment_tree<int> seg(f, 0);
	seg.build(a.begin(), a.end());

	for (int _ = 0; _ < k; _++) {
		dual_segment_tree<int> buff(f, 0);
		buff.resize(n);
		for (int i = 0; i < n; i++) {
			int d = seg[i];
			buff.update(max(0, i - d), min(n, i + d + 1), 1);
		}
		bool fin = true;
		for (int i = 0; i < n; i++) {
			fin &= (buff[i] == n);
		}
		seg.swap(buff);
		if (fin) break;
	}
	
	for (int i = 0; i < n; i++) cout << seg[i] << ' ';
	
	return 0;
}