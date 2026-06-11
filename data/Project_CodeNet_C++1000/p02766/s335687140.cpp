#include <iostream>
#include <algorithm>
using namespace std;

const string key = "0123456789";
string convert(int num, int base) 
{
	string result = "";
	while (num > 0) 
	{
		int remainder = num % base;
		result += key[remainder];
		num -= remainder;
		num /= base;
	}
	string reverse(result.rbegin(), result.rend());
	return reverse;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s = convert(n, k);
    cout << s.length() << endl;
}