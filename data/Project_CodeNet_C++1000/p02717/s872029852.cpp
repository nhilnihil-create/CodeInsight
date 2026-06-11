#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int X, Y, Z;
	int A, B, C;
	cin >> X >> Y >> Z;

	A = X, B = Y, C = Z;
	A = Y, B = X, C = Z;
	A = Z, B = X, C = Y;

	printf("%d %d %d\n", A, B, C);
	return 0;
}