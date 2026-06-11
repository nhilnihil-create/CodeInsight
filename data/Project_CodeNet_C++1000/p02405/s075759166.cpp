#define _USE_MATH_DEFINES

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>


using namespace std;

/* cout << fixed << setprecision(5); */



int main()
{
	int H, W;

	while (cin >> H >> W)
	{
		if (H == 0 && W == 0)
		{
			break;
		}


		for (int j = 0; j < H / 2; j++)
		{


			for (int i = 0; i < W / 2; i++)
			{
				cout << "#.";
			}

			if (W % 2 == 1)
			{
				cout << "#";
			}

			cout << endl;



			for (int i = 0; i < W / 2; i++)
			{
				cout << ".#";
			}

			if (W % 2 == 1)
			{
				cout << ".";
			}

			cout << endl;


		}



		if (H % 2 == 1)
		{
			for (int i = 0; i < W / 2; i++)
			{
				cout << "#.";
			}


			if (W % 2 == 1)
			{
				cout << "#";

			}


			cout << endl;

		}


		cout << endl;


	}
		
	
	return 0;
	

}