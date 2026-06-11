#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <stdio.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	if (a - (b * 2) > 0) {

		printf("%d", a - (b * 2));	
	}
	else {
		printf("%d", 0);
	}
}