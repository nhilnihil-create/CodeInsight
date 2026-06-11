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
int n, m, a[N];
ll ans;
int  main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	for (int i = m; i < n; i++)
		ans += a[i];
	printf("%lld\n", ans);
}