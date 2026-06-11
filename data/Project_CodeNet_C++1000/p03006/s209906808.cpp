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

LL N;
vector<LL> X, Y, P, Q;
int done[52] = {0};

LL sameClass(LL u1, LL v1, LL u2, LL v2, LL p, LL q){
	LL ret = INF;
	LL du = u2 - u1;
	LL dv = v2 - v1;
	if(p != 0 && (du % p) == 0){
		LL a = du / p;
		if(dv == a*q){
			ret = a;
		}
	}
	if(p == 0 && du == 0){
		LL a = dv / q;
		ret = a;
	}
	return ret;
}

LL calcCost(LL x, LL y, LL p, LL q){
	vector<LL> v;
	for(int i=0; i<N; i++){
		if(x == X[i] && y == Y[i]){
			if(done[i] == 1){
				return 0LL;
			}
			else{
				continue;
			}
		}
		LL r = sameClass(x, y, X[i], Y[i], p, q);
		if(r != INF){
			v.push_back(r);
			done[i] = 1;
		}
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	LL cost = 1;
	for(int i=1; i<v.size(); i++){
		if((v[i] - v[i-1]) != 1){
			cost++;
		}
	}
	return cost;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		LL x, y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}

	if(N == 1){
		printf("1\n");
		return 0;
	}

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			LL p = X[j] - X[i];
			LL q = Y[j] - Y[i];
			P.push_back(p);
			Q.push_back(q);
			P.push_back(p*(-1));
			Q.push_back(q*(-1));
		}
	}

	LL mincost = INF;
	for(int i=0; i<P.size(); i++){
		LL cost = 0;
		LL aP = P[i];
		LL aQ = Q[i];
		for(int j=0; j<N; j++){
			if(done[j] == 1){ continue; }
			cost += calcCost(X[j], Y[j], aP, aQ);
			done[j] = 1;
		}
		if(mincost > cost){
			mincost = cost;
		}
		for(int j=0; j<N; j++){
			done[j] = 0;
		}
	}
	printf("%lld\n", mincost);
	return 0;
}
