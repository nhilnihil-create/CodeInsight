#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", n* (n - 1) / 2);
}

