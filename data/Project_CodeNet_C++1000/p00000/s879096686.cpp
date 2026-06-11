#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}