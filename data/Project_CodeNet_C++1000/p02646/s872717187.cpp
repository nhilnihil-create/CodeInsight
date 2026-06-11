#include <bits/stdc++.h>
using namespace std;

int main (){
	long long a, b, v, w, t;
	scanf("%lld%lld%lld%lld%lld", &a, &v, &b, &w, &t);
	if(v * t >= ((a - b) > 0 ? (a - b) : (b - a)) + w * t){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
