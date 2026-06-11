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
	int s, w;
	scanf("%d %d", &s, &w);
	if (s <= w) printf("unsafe\n");
	else printf("safe\n");
}