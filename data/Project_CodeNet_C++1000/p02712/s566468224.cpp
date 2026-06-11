#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll; 
typedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
int n;
ll C(ll x){
	ll num = n / x;
	return (x + num * x) * num / 2;
}
int  main()
{
	scanf("%d", &n);
	printf("%lld", 1ll * (1 + n) * n / 2 - C(3) - C(5) + C(15));
}