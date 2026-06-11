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
	string s;
	cin >> n;
	cin >> s;
	
	int counter = 0;
	
	vector<bool> flags1;
	for (int number = 0; number < 10; number++)
	{
		flags1.push_back(false);
	}
	
	for (int i = 0; i < (n - 2); i++)
	{
		char c1 = s[i];
		if (flags1[c1 - '0'] == true)
		{
			continue;
		}
		flags1[c1 - '0'] = true;
		
		vector<bool> flags2;
		for (int number = 0; number < 10; number++)
		{
			flags2.push_back(false);
		}
		
		for (int j = (i + 1); j < (n - 1); j++)
		{
			char c2 = s[j];
			if (flags2[c2 - '0'] == true)
			{
				continue;
			}
			flags2[c2 - '0'] = true;
			
			vector<bool> flags3;
			for (int number = 0; number < 10; number++)
			{
				flags3.push_back(false);
			}
			
			for (int k = (j + 1); k < n; k++)
			{
				char c3 = s[k];
				if (flags3[c3 - '0'] == true)
				{
					continue;
				}
				flags3[c3 - '0'] = true;
				counter++;
			}
		}
	}
	
	
	cout << counter << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
