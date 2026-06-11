#include <iostream>

using namespace std;

int fx(int x)
{
	return x * x;
}


int main()
{
	int i, d, s;
	
	while(cin >> d)
	{
		s = 0;
		for(i = 1; d * i <= (600 - d); i++)
		{
			s = s + fx(d * i) * d;
		}
		
		cout << s << endl;
	}
	
	return 0;
}