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
using namespace std;


int main() { 	
	long long n, 
		a[80] = {0}, 
		money = 1000, 
		num_stocks = 0; 
	
	// Input 
	cin >> n; 
	for(int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	
	// Loop through stocks 
	for(int i = 0; i+1 < n; i++) {
		num_stocks = money / a[i]; 
		money += num_stocks * max(a[i+1]-a[i],0LL); 
	}
	
	cout << money << endl; 
	
	return 0; 
} 
