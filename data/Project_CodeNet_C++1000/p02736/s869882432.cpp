#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, s[1000005];

void diff(){
	for(int i = 1; i < n; i++){
		s[i] = abs(s[i] - s[i + 1]);
	}
	n--;
}

int tau(int x){
	int ret = 0;
	while(x > 0){
		ret += x / 2;
		x /= 2;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char c;
		scanf(" %c", &c);
		s[i] = c - '0';
	}
	// answer has to be 0, 1, or 2
	// parity should give "1" vs "0 or 2"
	int parity = 0;
	for(int i = 1; i <= n; i++){
		// check whether (n-1)C(i-1) is odd
		int twopow = tau(n-1) - tau(i-1) - tau(n-i);
		if(twopow == 0){
			parity ^= (s[i] & 1);
		}
	}
	if(parity == 1){
		printf("1\n");
		return 0;
	}
	
	diff();
	// now every entry needs to be 0 or 2, for answer to be 2
	for(int i = 1; i <= n; i++){
		if(s[i] == 1){
			printf("0\n");
			return 0;
		}
	}
	// use parity again!
	int answer = 0;
	for(int i = 1; i <= n; i++){
		int twopow = tau(n-1) - tau(i-1) - tau(n-i);
		if(twopow == 0){
			answer ^= s[i];
		}
	}
	printf("%d\n", answer);
	return 0;
}