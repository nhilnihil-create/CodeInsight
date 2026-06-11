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

	int L, R, d;
	cin >> L >> R >> d;

	int ans = 0;
	for(int i=L; i<=R; i++){
		if((i % d) == 0){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}