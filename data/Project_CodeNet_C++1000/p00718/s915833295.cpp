#include<iostream>
#include<string>
#include<sstream>
using namespace std;
static string mark = "mcxi";
static int value[] = { 1000, 100, 10, 1 };
int decode(string source)
{
	int index = 0;
	int sum = 0;
	while (index < source.size())
	{
		if (isalpha(source[index]))
		{
			if (index - 1 < 0 || !isdigit(source[index - 1]))
			{
				int i = mark.find(source[index]);
				sum += value[i];
			}
			else
			{
				int i = mark.find(source[index]);
				sum += (value[i] * (source[index - 1] - '0'));
			}
		}
		index++;
	}
	return sum;
}

string encode(int n)
{
	string ret = "";
	int rank = 3;
	while (n > 0 && rank >= 0)
	{
		int mod = n % 10;
		if (mod == 1)
		{
			ret = mark[rank] + ret;
		}
		else if (mod != 0)
		{
			ostringstream stream;
			stream << mod;
			string res = stream.str();
			ret = res + mark[rank] + ret;
		}

		n /= 10;
		rank--;
	}
	return ret;
}
int main()
{
	int n;
	cin >> n;
	string a;
	string b;
	for (int i = 0; i < n; i++)
	{
		char c[9], h[9];
		cin >> c >> h;
		a = c;
		b = h;
		int x = decode(a);
		int y = decode(b);
		int sum = x + y;
		string ans = encode(sum);
		cout << ans << endl;
	}
	return 0;
}