#include <iostream>
#include <vector>

int main()
{
	while (true) {
		int m, nmin, nmax;
		std::cin >> m >> nmin >> nmax;

		if (m == 0) {
			break;
		}

		std::vector<int>ps;
		ps.resize(m);

		for (int i = 0; i < m; i++) {
			std::cin >> ps.at(i);
		}

		int maxgap = -1;
		int ans = -1;
		for (int i = nmin; i <= nmax; i++) {
			int gap = ps.at(i - 1) - ps.at(i);

			if (gap >= maxgap) {
				maxgap = gap;
				ans = i;

			}

		}

		std::cout << ans << std::endl;
	}

	return 0;
}