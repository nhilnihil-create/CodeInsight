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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);


LL S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> S;
	LL a, c;
	LL b, d;
	for(a=1; ; a++){
		if( a >= 1000000000LL || a*a > S){
			break;
		}
	}

	d = a;
	LL u = (a*d) - S;
	b = 1;
	c = u;
	if(c > 1000000000LL){
		while(c >= 1000000000LL){
			d--;
			u = abs((a*d) - S);
			c = u;
		}
	}
	printf("0 0 %lld %lld %lld %lld\n", a, c, b, d);
	return 0;
}