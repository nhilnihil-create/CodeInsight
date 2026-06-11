#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::list<int> p(n), q(n);
	for (auto &e : p) std::cin >> e;
	for (auto &e : q) std::cin >> e;
	
	if (p > q) std::swap(p, q);
	int diff = 0;
	int k = 1;
	for (int i = 2; i < n; i++) k *= i;
	std::list<int> lsp(n), lsq(n);
	std::iota(lsp.begin(), lsp.end(), 1);
	std::iota(lsq.begin(), lsq.end(), 1);
	int d;
	for (auto itp = p.begin(), itq = q.begin(); *itp != p.back(); itp++, itq++) {
		d = std::distance(lsq.begin(), std::find(lsq.begin(), lsq.end(), *itq))
			- std::distance(lsp.begin(), std::find(lsp.begin(), lsp.end(), *itp));
		diff += d * k;
		lsp.remove(*itp);
		lsq.remove(*itq);
		n--;
		k /= n;
	}
	
	std::cout << diff << std::endl;
	
	return 0;
}
