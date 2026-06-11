/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces

Compile: g++  -o D.exe D.cpp 
Execute: ./D
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
	int s; 
	long long r[2001]; 
	long long mod = 1000000007; 

	cin >> s; 
	
	// Base cases 
	fill_n(r, 2001, 1); 
	r[0] = 0; 
	r[1] = 0; 
	r[2] = 0; 
	
	for(int i = 6; i <= 2000; i++) {
		for(int j = 3; j <= i-3; j++) {
			r[i] += r[j]; 
			r[i] %= mod; 
		}
	}
	
	cout << r[s] << endl; 
	
	return 0; 
} 
