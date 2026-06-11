#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int getTail(long long v){
	return int (v % 10);
}

int getHead(long long v){
	long long ret = v;
	while(true){
		long long tmp = ret / 10;
		if(tmp == 0){
			return ret;
		}
		ret = tmp;
	}
}

long long pow10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
long long N;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	long long ans = 0;
	for(int i=1; i<=N; i++){
		if((i % 10) == 0) continue;
		int a = getHead(i);
		int b = getTail(i);
		int next = 1;
		//iのペアが1桁 (i, a) をカウントする
		if(a == b && a <= N){
			ans++;
		}
		//iのペアが2桁以上の場合 2桁から6桁
		for(int j=2; j<=6; j++){
			long long v = pow10[j - 1] * b + a;
			if(v > N){
				continue;
			}
			int mid = j - 2;
			for(int k=0; k < pow10[mid] ; k++){
				long long w = v + 10 * k;
				if(w <= N){
					ans++;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}