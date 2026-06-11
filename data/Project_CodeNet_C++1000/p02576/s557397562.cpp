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
	int N, X, T;

	cin >> N >> X >> T;

	int times = ceil((double)N / X);

	cout << T * times << endl;
}