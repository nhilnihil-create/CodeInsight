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
char s[maxn],t[maxn];
int main()
{
	scanf("%s%s",s+1,t+1);
	int len=strlen(s+1);
	int ans=0;
	for(int i=1;i<=len;i++)
	if(s[i]!=t[i])
	ans++;
	printf("%d\n",ans);
}