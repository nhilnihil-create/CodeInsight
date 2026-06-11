#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, i = 1;
    scanf("%lld", &n);
    while(2*i <= n)
    	i *= 2;
    printf("%lld\n", 2*i-1);
	return 0;
}


