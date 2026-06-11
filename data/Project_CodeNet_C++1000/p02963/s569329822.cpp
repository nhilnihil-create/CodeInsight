#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int LIM = 1000000000;

long long S;
int remain;

int main(){
	scanf("%lld", &S);
	remain = S % LIM;
	remain = (LIM - remain) % LIM;
	
	// x_3 y_2 - x_2 y_3 = S
	printf("0 0 1 %lld %lld %lld\n", LIM, (S + remain) / LIM, remain);
	return 0;
}
