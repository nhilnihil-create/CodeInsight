#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	ll N, D, A;
	cin >> N >> D >> A;
	ll X[200000];
	ll H[200000];
	for(int i = 0; i < N; i++){
		cin >> X[i] >> H[i];
	}
	
	map<ll, ll> monsters;
	map<ll, ll> bomb;
	for(int i = 0; i < N; i++){
		monsters[X[i]] = H[i];
		bomb[X[i]] = 0;
	}
	
	ll ans = 0;
	auto itr = monsters.begin();
	for(int i = 0; i < N; i++){
		auto lower = bomb.lower_bound(itr->first - 2 * D);
		ll remainHP = itr->second;
		if(itr != monsters.begin()){
			remainHP -=bomb[prev(itr)->first] * A;
		}
		if(lower != bomb.begin()){
			remainHP += bomb[prev(lower)->first] * A;
		}
		if(remainHP > 0){
			ans += remainHP / A + (remainHP % A == 0 ? 0 : 1);
			bomb[itr->first] = remainHP / A + (remainHP % A == 0 ? 0 : 1);
		}
		if(itr!=monsters.begin()){
			// ボムを投げた回数の総和を記録しておく.
			bomb[itr->first] += bomb[prev(itr)->first];
		}
		itr++;
	}
	cout << ans << endl;
	
	return 0;
}