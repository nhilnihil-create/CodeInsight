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
	for (int i = 0; i < (n - 2); i++)
	{
		if ((s[i] == 'A') && (s[i + 1] == 'B') && (s[i + 2] == 'C'))
		{
			counter++;
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
