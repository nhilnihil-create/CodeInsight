#include <bits/stdc++.h>
#define D(x) cout << #x << "=" << x << endl
#define De(...)
using namespace std; 

int _; 
 
inline int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

int k;
long long ans;

int main()
{
	//for(scanf("%d",&_);_;_--)
	scanf("%d",&k);
	for(int i=1;i <= k;i++)
		for(int j=1;j <= k;j++)
			for(int h=1;h <= k;h++)
				ans += gcd(gcd(i,j),h);
	printf("%d\n",ans);
	return 0;
}
