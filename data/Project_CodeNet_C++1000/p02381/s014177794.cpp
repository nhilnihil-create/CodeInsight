#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{	

	
	for (;;)
	{
		int num, val[1000];
		cin >> num;
		double sum = 0, ave = 0;

		if (num == 0)
			break;


		for (int i = 0; i < num; i++)
		{
			cin >> val[i];
			ave += val[i];
		}

		ave = ave/num;

		for (int i = 0; i < num; i++)
		{
			sum += ((double)val[i] - ave) * ((double)val[i] - ave);
		}

		cout << sqrt(sum /num) << endl;


	}
	

}