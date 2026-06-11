/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces

Compile: g++  -o B.exe B.cpp 
Execute: ./B
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
	long long a, b, c, d; 
	priority_queue<long long> values; 
	
	cin >> a >> b >> c >> d; 
	
	values.push(a*c);
	values.push(a*d);
	values.push(b*c);
	values.push(b*d); 	
	
	cout << values.top() << endl ;
	
	return 0; 
} 
