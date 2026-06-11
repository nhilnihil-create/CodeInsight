#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int y, x;
	while (1) {
		cin >> y >> x;
		if (y == 0 && x == 0)break;
		for (size_t i = 0; i < y; i++)
		{
			if (i == 0||i==y-1) {
				for (size_t i = 0; i < x; i++)
				{
					cout << '#';
				}
			}
			else {
				for (size_t i = 0; i < x; i++)
				{
					if(i==0||i==x-1){ cout << '#'; }
					else { cout << '.'; }
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}