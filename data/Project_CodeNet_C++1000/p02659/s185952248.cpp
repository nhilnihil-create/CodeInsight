#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


int main() {
    uint64_t A;
	string B;

	cin >> A >> B;
	int len = B.length();

	B.erase(remove(B.begin(), B.end(), '.'), B.end());

	uint64_t b = atoll(B.c_str());
	B = to_string(A * b);

	switch (len)
	{
		case 3:
			if (B.length() > 1)
				B = B.substr(0, B.size() - 1);
			else
				B = "0";
			break;
		case 4:
			if (B.length() > 2)
				B = B.substr(0, B.size() - 2);
			else
				B = "0";
			break;
		case 1:
		case 2:
		default:
			break;
	}

	cout << B << endl;
	return 0;
}

