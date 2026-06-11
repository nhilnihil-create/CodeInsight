#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<map>
typedef long long int ll;
using namespace std;
#define maxn 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int mm=2e5+100;
using namespace std;
int main()
{
	int n,m,l,a,b,s;
	while(~scanf("%d%d",&n,&m))
	{
		 s=n/(2*m+1);
		 if(n!=(2*m+1)*s)
            s++;
		 printf("%d\n",s);
	}
	
	 
}