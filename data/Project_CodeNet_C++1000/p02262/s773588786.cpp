#include <iostream>
#include <ostream>
#include <vector>

void trace_space(std::vector<int> v) {
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void trace_endl(std::vector<int> v) {
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << std::endl;
	}
}

void insertion_sort(std::vector<int> &v, int n, int g, int &cnt) {
	for (int i = g; i < n; i++) {
		int t = v[i];
		int j = i - g;
		while (j >= 0 && v[j] > t) {
			v[j + g] = v[j];
			j = j - g;
			cnt++;
		}
		v[j + g] = t;
	}
}

void shell_sort(std::vector<int> &v, int n) {
	std::vector<int> G;
	for (int g = 1; g <= n; g = 3 * g + 1)
		G.push_back(g);
	
	int c = 0;
	for (int i = 0; i < G.size(); i++) {
		insertion_sort(v, n, G[G.size()-i-1], c);
	}
	// 
	std::cout << G.size() << std::endl;
	for (int i = 0; i < G.size()-1; i++) {
		std::cout << G[G.size() - i - 1] << " ";
	}
	std::cout << G[0] << std::endl;

	std::cout << c << std::endl;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	shell_sort(a, n);
	trace_endl(a);
	return 0;
}