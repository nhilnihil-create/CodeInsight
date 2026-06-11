#include <iostream> 
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	for(int a = n / 2, b = a + 1, c = 1; c <= m; a--, b++, c++)
	{
		if(n % 2 == 0 && (b - a == n / 2 || b - a == n / 2 + 1))
		{
			b++;
		}
		cout << a << ' ' << b << endl;
	}
	return 0;
}