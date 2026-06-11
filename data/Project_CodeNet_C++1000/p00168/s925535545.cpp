#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int p[31];
	p[0] = 1;
	p[1] = 1;
	p[2] = 2;
	for (int i = 3; i <= 30; ++i)
	{
		p[i] = p[i-1] + p[i-2] + p[i-3];
	}
	while(1){
		int y, n;
		cin >> n;
		if(n == 0){
			break;
		}
		y = p[n] / 10 / 365 + 1;
		
		cout << y << endl;
	}
	return 0;
}