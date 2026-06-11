#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	int num_of_letters = 1;
	long long first = 1;
	long long temp_size = 26;
	while (n > first + temp_size - 1)
	{
		num_of_letters++;
		first += temp_size;
		temp_size *= 26;
	}
	n -= first;
	string res(num_of_letters, 'a');
	int pos = res.size() - 1;
	while (n > 0)
	{
		res[pos--] = (n % 26) + 'a';
		n /= 26;
	}
	cout << res << endl;
}