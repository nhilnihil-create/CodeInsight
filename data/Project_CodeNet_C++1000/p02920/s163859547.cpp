#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using u32 = uint32_t;

int main()
{
	std::ios_base::sync_with_stdio(0);
	u32 n;
	
	std::cin >> n;

	u32 m = std::pow(2, n);
	
	std::vector<u32> v;
	v.reserve(m);

	std::map<u32, u32, std::greater<u32>> hist;
	
	for(u32 i = 0; i < m; i++)
	{
		u32 x;
		std::cin >> x;
		hist[x]++;
	}
/*
	std::cout << "map:\n";

	for(auto it = hist.begin(); it != hist.end(); it++)
	{
		std::cout << (*it).first << ": " << (*it).second << "\n";
	}

	std::cout << "\n";
*/
	v.push_back((*(hist.begin())).first);

	for(u32 i = 0; i < n; i++)
	{
		for(auto it = v.begin(); it != v.begin() + std::pow(2, i); it++)
		{
			//std::cout << "it = " << *it << "\n";
			auto lb = hist.lower_bound((*it)-1);
			bool ok = false;
			while (lb != hist.end()) {
				if((*lb).first < *it) {
					//std::cout << " " << (*lb).first << " : " << (*lb).second << "\n";
					ok = true;
					break;
				}
				lb++;
			}

			if (!ok) {
				std::cout << "No\n";
				return 0;
			}
			else
			{
				(*lb).second--;
				v.push_back((*lb).first);
				if((*lb).second == 0)
				{
					hist.erase(lb);
				}
			}
		}
/*
		std::cout << "i = " << i << "\n";
		for(u32 j = 0; j < v.size(); j++)
		{
			std::cout << v[j] << " ";
		}

		std::cout << "\n";*/
	}

	std::cout << "Yes\n";
	
	return 0;
}