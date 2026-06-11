#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	ll N;
	vector<char> digits;
	cin >> N;
	while(N >= 1)
	{
		N -= 1;
		digits.push_back('a' + N % 26);
		N /= 26;
	}
	while (1)
	{
		cout << digits.back();
		digits.pop_back();
		if (digits.size() == 0)
			break;
	}
	cout << endl;
	return 0;
 }
