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
	N = N % 10;

	if (N == 2 || N == 4 || N == 5 || N == 7 || N == 9) {
		cout << "hon" << endl;
	}
	else if (N == 0 || N == 1 || N == 6 || N == 8) {
		cout << "pon" << endl;
	}
	else {
		cout << "bon" << endl;
	}
}