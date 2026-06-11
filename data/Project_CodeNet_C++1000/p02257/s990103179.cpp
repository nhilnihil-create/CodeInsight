#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define rep(i,o,u) for(int i = o;i <= u; i++)
typedef unsigned long long ll;
using namespace std;
int isPrime(int a){
	if(a == 2) return 1;
	if(a % 2 == 0) return 0;
	for(int i = 2;i <= sqrt(a); i++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n,a,ans = 0;
	cin >> n;
	while(n--){
		cin >> a;
		if(isPrime(a)) ans++;
	}
	cout << ans << endl;
	return 0;
}