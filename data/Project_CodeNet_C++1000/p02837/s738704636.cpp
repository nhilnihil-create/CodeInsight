// template.cpp

// Defines.
//#define DEBUG
#define NUMBER_OF_DIGITS 6

// Includes.
#include <bits/stdc++.h>

#ifdef DEBUG
#include <chrono>
#endif

// Usings.
using namespace std;

// Main function.
int main()
{
#ifdef DEBUG
	chrono::system_clock::time_point start, end;
	
	start = chrono::system_clock::now();
#endif
	
	// settings.
	ios::sync_with_stdio(false);
	
	//cout << fixed;
	//cout << setprecision(NUMBER_OF_DIGITS);
	
	// logic.
	int n;
	cin >> n;
	
	int xs[n];
	int ys[n];
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		
		int x = 0;
		int y = 0;
		for (int j = 0; j < a; j++)
		{
			int x_in, y_in;
			cin >> x_in >> y_in;
			
			x |= (1 << (x_in - 1));
			if (y_in == 1)
			{
				y |= (1 << (x_in - 1));
			}
			else
			{
				y &= (~(1 << (x_in - 1)));
			}
		}
		
		xs[i] = x;
		ys[i] = y;
	}
	
	int max = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) != 0)
			{
				if (((xs[j] & ys[j]) & i) != (xs[j] & ys[j]))
				{
					flag = false;
					break;
				}
				
				if (((xs[j] & (~ys[j])) & (~i)) != (xs[j] & (~ys[j])))
				{
					flag = false;
					break;
				}
			}
		}
		
		if (flag == true)
		{
			if (__builtin_popcount(i) > max)
			{
				max = __builtin_popcount(i);
			}
		}
	}
	
	cout << max << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
