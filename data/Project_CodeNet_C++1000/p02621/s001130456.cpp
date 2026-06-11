#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<ext/pb_ds/priority_queue.hpp>
#include<set>
#include<map>
#include<math.h>
#include<set>
#define maxn 500005
#define lson (now<<1)
#define rson ((now<<1)|1)
typedef long long ll;
using namespace std;
using namespace __gnu_pbds; 
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d\n",x+x*x+x*x*x);
}