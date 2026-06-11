#include <iostream>
#include <vector>

int main()
{
	int n;
	int a, b;
	std::vector<int> ansa;
	std::vector<int> ansb;
	int sa;
	int sb;
	
	while(1) {
		std::cin >> n;
		if (n == 0) {
			break;
		}
		sa = 0;
		sb = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a >> b;
			if (a > b) {
				sa += a + b;
			}
			else if (a == b) {
				sa += a;
				sb += b;
			}
			else {
				sb += a + b;
			}
		}
		ansa.push_back(sa);
		ansb.push_back(sb);
	}

	for (int i = 0; i < ansa.size(); i++)
	{
		std::cout << ansa[i] << " " << ansb[i] << std::endl;
	}

	return 0;
}