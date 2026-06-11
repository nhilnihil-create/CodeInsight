#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
	int k, a, b;
	cin >> k >> a >> b;
	for(int i = a; i<=b; i++) {
		if (i%k == 0){
			puts("OK");
			return 0;
		}
	}
	puts("NG");
	return 0;
}