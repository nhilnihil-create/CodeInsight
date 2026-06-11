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

int main(void) {
	cin.tie(0); ios::sync_with_stdio(0);
	
	int n, x, t;
	cin >> n >> x >> t;
	if (n % x != 0) n += x;
	cout << ((int)(n / x)) * t << '\n';
}





/*
C:\Users\User\Desktop\comp_programming\final_straw_after_this_im_switching_to_vs_code\final_straw_after_this_im_switching_to_vs_code.cpp
*/