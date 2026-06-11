#include <iostream>
using namespace std;

int main()
{
	unsigned long long n;
	string s;
	cin >> n;
	//Ascii from 97 to 122 (+96)
	while (true)
	{
		if (n % 26 == 0)
		{
			s += 'z';
			n /= 26;
			n--;
		}
		else
		{
			s += (char)((n % 26) + 96);
			n = n / 26;
		}
		if (n == 0) break;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;

	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	return 0;
}