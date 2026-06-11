#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
#define MAX_N 2000001
bool isPrime[MAX_N];
void init(){
	rep(i,MAX_N) isPrime[i] = true;
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i*i <= MAX_N; i++){
		if( isPrime[i] == true){
			for(int j = 2; j*i < MAX_N; j++) isPrime[i*j] = false;
		}
	}
}

bool isItPrime(ll num){
	if( num == 1) return false;
	for(int i = 2; i < MAX_N; i++){
		if( isPrime[i] == true && num % i == 0) return false;
	}
	return true;
}

ll stair(ll num){
	for(int i = 1; i < MAX_N; i++){
		if( i*(i+1)/2 <= num && num < (i+1)*(i+2)/2){
			return i;
		}
	}
}


int main(){
	init();
	ll n;
	cin>>n;
	vector<pair<int,int>> divisors;
	ll ans = 0;
	if( n >= MAX_N && isItPrime(n) == true){
		n = 1;
		ans = 1;
	}
	
	for(int i = 2; i < MAX_N; i++){
		if( n == 1) break;
		if( isPrime[i] == true && n % i == 0){
			divisors.push_back(make_pair(i,1));
			n /= i;
			while( n % i == 0){
				divisors.back().second++;
				n /= i;
			}
		}
	}
	
	if( n >= MAX_N && isItPrime(n) == true){
		n = 1;
		ans += 1;
	}
	
	for(auto iter = divisors.begin(); iter != divisors.end(); iter++){
		//cout<<iter->first<<":"<<iter->second<<endl;
		//ans++;
		ans += stair(iter->second);
	}
	cout<<ans<<endl;
	return 0;
}
