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

int main()
{
	//for(scanf("%d",&_);_;_--)
	scanf("%d",&k);
	int ans=k*360/gcd(k,360);
	printf("%d\n",ans/k);
	return 0;
}
