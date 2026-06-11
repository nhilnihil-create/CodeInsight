#include <bits/stdc++.h>
using namespace std;


int main() {
	int X;
	cin >> X;
	while (true)
	{

		int div = X-1;
		bool hav = false;
		while (true)
		{
			if (div == 1) {
				hav = true;
				break;
			}
			if (X % div == 0)
			{
				
				break;
			}
			div--;
			
		}
		
		if (hav)break;
		
		X++;
	}
	cout << X << endl;
}