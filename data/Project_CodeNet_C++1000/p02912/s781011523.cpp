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

static long long INF = (1LL<<62);

void delMapKey(map<long long, int> &m, long long k){
	if(m.count(k) == 0){
		return;
	}
	m[k]--;
	if(m[k] == 0){
		m.erase(m.find(k));
	}
}

void addMapKey(map<long long, int> &m, long long k){
	if(m.count(k) == 0){
		m[k] = 1;
	}
	else{
		m[k]++;
	}
}

long long getHeadKey(map<long long, int> &m){
	if(m.size() == 0){
		return INF;
	}
	long long ret = m.begin()->first;
	return ret;
}

long long getLastKey(map<long long, int> &m){
	if(m.size() == 0){
		return INF;
	}
	long long ret = m.crbegin()->first;
	return ret;
}

LL N, M;
map<LL, int> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		addMapKey(A, a);
	}

	for(int i=0; i<M; i++){
		LL a = getLastKey(A);
		delMapKey(A, a);
		a = a / 2;
		addMapKey(A, a);
	}
	long long ans = 0;
	for(auto itr = A.begin(); itr != A.end(); itr++){
		long long a = itr->first;
		int v = itr->second;
		ans += (a * v);
	}
	printf("%lld\n", ans);
	return 0;
}