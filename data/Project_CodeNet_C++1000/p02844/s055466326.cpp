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
	
	string s;
	cin >> s;
	
	map<char, bool> s0_cache, s1_cache;
	for (char i = '0'; i < ('0' + 10); i++)
	{
		s0_cache[i] = false;
		s1_cache[i] = false;
	}
	
	set<string> keys;
	for (int i = 0; i < (n - 2); i++)
	{
		if (s0_cache[s[i]] == true)
		{
			continue;
		}
		else
		{
			s0_cache[s[i]] = true;
		}
		
		for (int j = (i + 1); j < (n -1); j++)
		{
			if (s1_cache[s[j]] == true)
			{
				continue;
			}
			else
			{
				s1_cache[s[j]] = true;
			}
			
			for (int k = (j + 1); k < n; k++)
			{
				char key[3];
				key[0] = s[i];
				key[1] = s[j];
				key[2] = s[k];
				
				keys.insert(key);
			}
		}
				
		for (char j = '0'; j < ('0' + 10); j++)
		{
			s1_cache[j] = false;
		}
	}
	
	cout << keys.size() << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
