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


long long H;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H;

	if(H == 1){
		printf("1\n");
		return 0;
	}

	long long h = H, monster = 1, c = 1;
	while(true){
		h = h / 2;
		if(h == 0){
			break;
		}
		c *= 2;
		monster = monster + c;
	}
	printf("%lld\n", monster);
	return 0;
}