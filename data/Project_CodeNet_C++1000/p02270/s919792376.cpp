#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

long long int INF = 1e18;
using namespace std;

typedef pair<long long int, long long int> P;

long long int n, k;
long long int w[200000];

bool check(long long int num){
	int cnt = 0;
	long long int s = 0;
	for(int i = 0; i < n; i++){
		if(w[i] > num){
			return false;
		}
		if(s + w[i] > num){
			cnt++;
			s = w[i];
		}else{
			s += w[i];
		}
	}
	cnt++;
	if(cnt <= k){
		return true;
	}
	return false;
}

long long int bin_search(long long int lef, long long int rig){
	long long int middle = (lef + rig) / 2;
	//cout << middle << " ";
	if(rig - lef <= 1){
		if(check(lef)){
			return lef;
		}else{
			return rig;
		}
	}
	if(check(middle)){
		rig = middle;
	}else{
		lef = middle;
	}
	return bin_search(lef, rig);
}

int main(){
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	
	cout << bin_search(0, 1e18) << endl;
	
	return 0;
}
