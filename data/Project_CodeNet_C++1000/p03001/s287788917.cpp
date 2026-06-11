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

	long long W, H;
	long long x, y;
	cin >> W >> H >> x >> y;

	long double S;
	if(W <= H){
		S = (double)H / 2;
		S *= W;
	}
	else{
		S = (double)W / 2;
		S *= H;
	}
	if( (W % 2 == 0) && (H % 2 == 0) && x == W/2 && y == H/2){
		printf("%.10Lf 1\n", S);
	}
	else{
		printf("%.10Lf 0\n", S);
	}
	return 0;
}