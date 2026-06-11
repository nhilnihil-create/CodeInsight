#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

const long long mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	
	long long A = 1;
	for(int i  = 0; i < n; i++){
		A *= 10;
		A %= mod;
	}
	
	long long B = 1;
	for(int i  = 0; i < n; i++){
		B *= 9;
		B %= mod;
	}
	
	long long C = 1;
	for(int i  = 0; i < n; i++){
		C *= 8;
		C %= mod;
	}
	
	long long ans;
	
	ans = A + mod - B;
	ans %= mod;
	
	ans = ans + mod - B;
	ans %= mod;
	
	ans += C;
	ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}
 
