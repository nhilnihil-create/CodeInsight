#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>
#include <tuple>
#include <map> 
#include <set>
#include <stack>
#include <functional>
#define ll long long
using namespace std;

int main() {
	int N;

	cin >> N;

	N = N % 1000;
	if (N == 0) cout << 0 << endl;
	else cout << 1000 - N << endl;
}