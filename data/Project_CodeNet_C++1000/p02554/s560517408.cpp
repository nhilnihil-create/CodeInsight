/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces

Compile: g++  -o C.exe C.cpp 
Execute: ./C
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

/* 
Notes: 
	result = 10^n - 2 * 9^n + 8^n
	a = 10^n
	b = 9^n
	c = 8^n
	result = a - 2*b + c
*/ 

int main() { 
	long long mod = 1000000007; 
	int n; 
	long long a=1ull, b=1ull, c=1ull, result=0ull;
	
	cin >> n; 
	for(int i = 0; i < n; i++) {
		a *= 10; a %= mod; 
		b *=  9; b %= mod; 
		c *=  8; c %= mod; 
	}
	
	result += a; result %= mod; 
	result += 2*mod - 2*b; result %= mod; 
	result += c; result %= mod; 
	
	cout << result << endl; 
	
	return 0; 
} 
