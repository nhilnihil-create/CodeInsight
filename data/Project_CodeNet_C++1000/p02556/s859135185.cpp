/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces
 
Compile: g++  -o E.exe E.cpp 
Execute: ./E
*/ 
 
#include <cstdio>
#include <iostream>
#include <cmath> 
#include <limits> 
#include <iomanip>
#include <cstring> 
#include <bits/stdc++.h>
#include <string>  
#include <algorithm> 
using namespace std;
 
int main() { 	
	int n, x, y; 
	
	cin >> n; 
	int r[n], s[n];
	for(int i = 0; i < n; i++) {
		cin >> x >> y; 
		r[i] = (x+y); 
		s[i] = (x-y); 
	}
	
	int min_value_r = *min_element(r, r+n), 
		max_value_r = *max_element(r, r+n),
		min_value_s = *min_element(s, s+n), 
		max_value_s = *max_element(s, s+n);
	
	cout << max(max_value_r - min_value_r, max_value_s - min_value_s) << endl; 
	
	return 0; 
} 