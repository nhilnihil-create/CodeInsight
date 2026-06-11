#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct V {
	double x, y;
	V(double x = 0, double y = 0): x(x), y(y) {}
	
	void operator+=(const V& v) {
		x += v.x; y += v.y;
	}
	
	V operator+(const V& v) const {
		return V(x + v.x, y + v.y);
	}
	
	double dot(const V& v) const {
		return x * v.x + y * v.y;
	}
	
	double cross(const V& v) const {
		return x * v.y - y * v.x;
	}
	
	double norm2() const {
		return x * x + y * y;
	}
	
	double norm() const {
		return sqrt(norm2());
	}
	
	int ort() const {
		if (y >= 0) return x >= 0 ? 1 : 2;
		else return x >= 0 ? 4 : 3;
	}
	
	bool operator<(const V& v) const {
		if (ort() != v.ort()) return ort() < v.ort();
		return cross(v) > 0;
	}
};

int main() {
	int N;
	cin >> N;
	
	vector<V> A;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		A.emplace_back(x, y);
	}
	
	sort(A.begin(), A.end());
	
	double ans = 0;
	for (int i = 0; i < N; ++i) {
		V now;
		for (int j = 0; j < N; ++j) {
		    int index = (i + j) % N;
		    now += A[index];
		    ans = max(ans, now.norm());
		}
	}
	
	printf("%.12f\n", ans);
}