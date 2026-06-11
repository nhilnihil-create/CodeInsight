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

long long N;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	long long u = N;
	int flag = 0;

	while(u > 0){
		if((u % 10) == 7){
			flag = 1;
			break;
		}
		u /= 10;
	}
	if(flag){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
