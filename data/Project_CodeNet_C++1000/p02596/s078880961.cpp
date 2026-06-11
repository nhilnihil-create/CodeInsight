#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include<math.h>
#include <queue>
using namespace std;
#define Minf -1e9
#define scan(n) scanf("%lld",&n)
typedef long long ll;
const int maxn = 1*1e5+10;
const ll INF = 1e9+100;
const int mod = 998244353;

int a[maxn];
int main()
{
	int k;
	scanf("%d", &k);
	ll t = 0;
	int fmax = 1e7;
	int flag = 0;
	int i;
	for (i = 1; i <= fmax; i++){
		t = (t * 10 + 7) % k;
		if (t == 0){
			flag = 1;
			break;
		}
	}
	if (flag) cout << i << endl;
	else cout << "-1";
}