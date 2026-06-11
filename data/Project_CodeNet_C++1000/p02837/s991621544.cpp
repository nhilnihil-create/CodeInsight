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
		
		int honests[n];
		int unhonests[n];
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			int honest = 0;
			int unhonest = 0;
			for (int j = 0; j < a; j++)
			{
				int x, y;
				cin >> x >> y;
				
				if (y == 1)
				{
					honest |= (1 << (x - 1));
				}
				else
				{
					unhonest |= (1 << (x - 1));
				}
			}
			
			honests[i] = honest;
			unhonests[i] = unhonest;
		}
		
		int max = 0;
		for (int i = 0; i < (1 << n); i++)
		{
			bool all_ok = true;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					int honest = honests[j];
					int unhonest = unhonests[j];
					
					if ((honest | i) != i)
					{
						all_ok = false;
						break;
					}
					
					if ((unhonest & i) != 0)
					{
						all_ok = false;
						break;
					}
				}
			}
			
			if (all_ok == true)
			{
				if (max < __builtin_popcount(i))
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
