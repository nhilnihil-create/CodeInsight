#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1,x;i <= n; ++i)
	{
		scanf("%d",&x);
		ans += (i & 1) & (x & 1);
	}
	printf("%d\n",ans);
	return 0;
}