#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	while (true)
	{
		std::string str;
		int val = 0;
		if (std::getline(std::cin, str))
		{
			if (str[0] == '0')
			{
				break;
			}

			for (auto c : str)
			{
				val += c - '0';
			}
		}
		std::cout << val << std::endl;
	}
	return 0;
}
