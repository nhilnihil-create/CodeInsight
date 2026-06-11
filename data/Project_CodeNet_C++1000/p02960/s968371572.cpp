// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define MOD (int)(1e9 + 7) 

// Function to find the count of integers 
// obtained by replacing '?' in a given 
// string such that formed integer 
// gives remainder 5 when it is divided by 13 
int modulo_13(string s, int n) 
{ 
	long long dp[n + 1][13] = { { 0 } }; 

	// Initialise 
	dp[0][0] = 1; 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < 10; j++) { 
			int nxt = s[i] - '0'; 

			// Place digit j at ? position 
			if (s[i] == '?') 
				nxt = j; 

			// Get the remainder 
			for (int k = 0; k < 13; k++) { 
				int rem = (10 * k + nxt) % 13; 
				dp[i + 1][rem] += dp[i][k]; 
				dp[i + 1][rem] %= MOD; 
			} 
			if (s[i] != '?') 
				break; 
		} 
	} 

	// Return the required answer 
	return (int)dp[n][5]; 
} 

// Driver code 
int main() 
{ 
	string s = "?44"; 
  	cin>>s;
	int n=s.size(); 
	cout << modulo_13(s, n); 

	return 0; 
} 
