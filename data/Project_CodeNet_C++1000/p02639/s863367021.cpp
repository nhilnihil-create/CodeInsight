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

	int idx = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			idx = i + 1;
		}
	}
	cout << idx << endl;
}