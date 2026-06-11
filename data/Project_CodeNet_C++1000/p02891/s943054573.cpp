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
long long INF = (1LL<<62);
typedef long long LL;

LL func(string s){
	LL ret = 0;
	for(int i=1; i<s.size(); i++){
		if(s[i-1] == s[i]){
			ret++;
			i++;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	LL K;

	cin >> S;
	cin >> K;

	if(S.size() == 1){
		printf("%lld\n", K/2);
		return 0;
	}
	if(S.size() == 2){
		if(S[0] == S[1]){
			printf("%lld\n", K);
		}
		else{
			printf("0\n");
		}
		return 0;
	}

	LL ans = 0;

	string S1 = S;
	string S2 = S1 + S;
	string S3 = S2 + S;
	LL a1 = func(S1);
	LL a2 = func(S2);
	LL a3 = func(S3);
	LL d1 = a2 - a1;
	LL d2 = a3 - a2;
	if(d1 == d2){
		ans = a1 + (K-1)*d1;
	}
	else{
		ans = a1 + ((K-1)/2)*(d1+d2);
		if((K-1) % 2 == 1){
			ans += d1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}