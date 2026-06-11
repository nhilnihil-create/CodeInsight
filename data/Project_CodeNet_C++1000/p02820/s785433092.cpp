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


long long N, K;
long long R, S, P;
string T;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	cin >> R >> S >> P;
	cin >> T;
	int oops[100000+2] = {0};

	long long ans = 0;
	for(int i=0; i<K; i++){
		long long v = 0;
		int pos1, pos2;
		pos1 = i;
		if(T[pos1] == 'r') v = P;
		if(T[pos1] == 's') v = R;
		if(T[pos1] == 'p') v = S;
		
		for(int j=1; ; j++){
			int pos2 = i + (j * K) ;
			if(pos2 >= N) break;
			if(T[pos2] == T[pos1]){
				if( j== 1 || oops[pos1] == 0){
					oops[pos2] = 1;
				}
				else{
					if(T[pos2] == 'r') v += P;
					if(T[pos2] == 's') v += R;
					if(T[pos2] == 'p') v += S;
				}
			}
			else{
				if(T[pos2] == 'r') v += P;
				if(T[pos2] == 's') v += R;
				if(T[pos2] == 'p') v += S;
			}
			pos1 = pos2;
		}
		ans += v;
	}
	printf("%lld\n", ans);
	return 0;
}