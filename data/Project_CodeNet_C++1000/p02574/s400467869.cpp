#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <stdlib.h> 
#include <stdio.h>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <deque>
#include <stack>
#include <queue>
#include <fstream>
#include <limits>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <sstream>
#include <random>
#include <cassert>

using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;
bool pairwise_coprime = true;

void verify_factors(int n, vector <int>& is_factor) {
	if (pairwise_coprime == false) return;
	vector <int> factors;
	for (int i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		if (i * i == n) {
			factors.push_back(i);
		}
		else {
			if (i == n) {
				factors.push_back(i);
			}
			else {
				factors.push_back(i);
				factors.push_back(n / i);
			}
		}
	}

	for (auto e : factors) {
		if (e == 1) continue;
		if (is_factor[e]) {
			pairwise_coprime = false;
			break;
		}
		is_factor[e] = true;
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector <int> v(n), is_factor(1e6 + 5, false);
	ffor(n) cin >> v[i];
	
	for (auto e : v) verify_factors(e, is_factor);

	if (pairwise_coprime) {
		cout << "pairwise coprime";
	}
	else {
		int current = v[0];
		for (int i = 1; i < v.size(); i++) {
			current = gcd(current, v[i]);
		}
		if (current == 1) {
			cout << "setwise coprime";
		}
		else {
			cout << "not coprime";
		}
	}
}
	




/*
C:\Users\User\Desktop\comp_programming\final_straw_after_this_im_switching_to_vs_code\final_straw_after_this_im_switching_to_vs_code.cpp
*/