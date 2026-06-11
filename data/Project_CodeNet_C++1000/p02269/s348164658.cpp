#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	bool dic[10000000] = { 0 };
	long n = 0;
	long long k = 0;
	string st1, st2;

	cin >> n;

	for (long i = 0; i < n; i++) {
		cin >> st1 >> st2;
		k = 0;

		for(unsigned int j = 0; j < st2.size(); j++)
			switch (st2[j]) {
			case 'A':
				k += (long long)pow(5, j);
				break;
			case 'C':
				k += (long long)pow(5, j) * 2;
				break;
			case 'G':
				k += (long long)pow(5, j) * 3;
				break;
			case 'T':
				k += (long long)pow(5, j) * 4;
				break;
			}

		if (st1 == "insert")
			dic[k] = 1;
		else if (st1 == "find"){
			if(dic[k] == 1)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}