#include<iostream>
#include<vector>
#include<string>
int main() {
	int n;
	int a, b;
	std::vector<int> k,t;
	while (true)
	{
		std::cin >> n;
		if (n == 0)
			break;
		int g = 0;
		int s = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0)
				g -= g,
				s -= s;
			std::cin >> a >> b;
			if (a == b)g += a, s += b;
			if (a > b) g += a + b;
			if (a < b) s += b + a;
		}
		k.push_back(g);
		t.push_back(s);
	}
	for (int i = 0; i < k.size(); ++i) {
		std::cout << k[i] << " " << t[i] << std::endl;
	}
	return 0;
}