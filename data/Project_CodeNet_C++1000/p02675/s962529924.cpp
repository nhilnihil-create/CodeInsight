#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h> 
#include <stack>
#include <bitset>
#include <map>
#include <cmath>
#include <climits>
#include <queue>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n >= 10) n %= 10;

	if (n == 3) printf("bon\n");
	else if (n == 0 || n == 1 || n == 6 || n == 8) printf("pon\n");
	else printf("hon\n");
}