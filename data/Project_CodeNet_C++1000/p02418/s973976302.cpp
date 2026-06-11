#include <iostream>
#include <string>

int main(void)
{
	std::string s, p;
	std::cin >> s >> p;
	s += s;
	int count;
	bool contains = false;
	for (int i = 0; i + p.size() <= s.size(); i++)
	{
		count = 0;
		while (count < p.size() && p[count] == s[i + count])
		{
			count++;
		}
		if (count == p.size())
		{
			contains = true;
			break;
		}
	}
	std::cout << (contains ? "Yes" : "No") << '\n';
	return 0;
}