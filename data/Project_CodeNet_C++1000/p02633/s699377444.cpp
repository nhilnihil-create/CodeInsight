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

typedef unsigned long long LL;

LL N;
vector<LL> D;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int X;
	cin >> X;

	int ans = 0;
	while(true){
		if((X * ans) % 360 == 0 && ans != 0){
			break;
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}