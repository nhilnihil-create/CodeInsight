#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <cstdlib>
#include <string.h>


using namespace std;


int main()
{
	int count = 0, h = 0;
	string input;

	while (true)
	{
		
		cin >> input;
		cin >> count;

		if (input[0] == '-')
			break;

		for (int i = 0; i < count; i++)
		{
			cin >> h;

			input = input.erase(0, h) + input.substr(0, h);
		}

		cout << input << endl;
	}

	
}