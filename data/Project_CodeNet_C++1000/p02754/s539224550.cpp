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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	LL q = N / (A+B);
	LL r = N % (A+B);
	LL ans = A*q;
	if(r != 0){
		ans += min(r, A);
	}
	printf("%lld\n", ans);
	return 0;
}