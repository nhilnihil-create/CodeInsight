#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	std::string s;
	std::getline(std::cin, s);

	std::string p;
	std::getline(std::cin, p);

	for (int si = 0; si < (int)s.size(); ++si)
	{
		if (s[si] == p[0])
		{
			bool match = true;
			for (int pi = 0; pi < (int)p.size() && match; ++pi)
			{
				match = (s[(si + pi) % (int)s.size()] == p[pi]);
			}
			if (match)
			{
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}

	std::cout << "No" << std::endl;

	return 0;
}
