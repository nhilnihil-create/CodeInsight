#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

struct task{
	int cost;
	int deadLine;
};

bool myComp(task left,task right){
	return (left.deadLine < right.deadLine);
}

int main()
{
	int N,A,B,C;
	cin>>N;
	ll ans = 0;
	for(C = 1; C <= N-1; C++){
		if(N-C == 1){
			ans++;
		}else{
			for(A = 1; A*A <= (N-C); A++){
				if((N-C) % A == 0){
					B = (N-C)/A;
					if( A != B){
						ans += 2;
					}else{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

