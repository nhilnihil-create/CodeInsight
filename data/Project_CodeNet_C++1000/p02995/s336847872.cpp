#include <bits/stdc++.h>
// #include <algorithm>

using namespace std;

long long gcd(long long a, long long b) { // Greatest Common Denominator - Euclidean Algorithm
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) { // Lowest Common Multiple
	return (a * b) / gcd(a, b);
}

long long solve(long long x, long long c, long long d) { 
	return x - x / c - x / d + x / lcm(c, d);
}

int main() {
	
	long long A, B, C, D; 
	cin >> A >> B >> C >> D;

	long long b = B - B / C - B / D + B / lcm(C, D); 
	// // removes multiples of B and C and takes care of the duplicates for numbers <= A-1
	long long a =  A - 1 - (A - 1) / C - (A - 1) / D + (A - 1) / lcm(C, D);
	cout << b - a;
	// cout << solve(B, C, D) - solve(A - 1, C, D);
	return 0;
}
