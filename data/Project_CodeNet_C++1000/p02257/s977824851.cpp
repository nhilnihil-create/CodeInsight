#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int gcd(int a, int b) {
	if(a>b)swap(a,b);
	int c;
	while (a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

bool isPrime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(void){
	int n;cin >> n;
	int cnt=0;
	for(int i=0;i<n;i++){
		int a;cin >> a;
		if(isPrime(a))cnt++;
	}
	cout <<cnt << endl;
	return 0;
}