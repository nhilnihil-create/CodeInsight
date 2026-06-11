#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1000005;
int n,a[MAXN];
char str[MAXN];
inline int c(int n, int m)
    { return (n&m)==m; }
inline int calc()
{
	int res = 0;
	for(int i = 1; i<=n; i++)
	    if(c(n-1,i-1))
	        res ^= a[i]&1;
	return res; 
}

int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i = 1; i<=n; i++)
    	a[i] = str[i]-'1';
    bool flag = false;
	for(int i = 1; i<=n; i++)
        flag |= a[i]==1;
	if(flag) 
	    cout << calc() << endl;
	else
	{
        for(int i = 1; i<=n; i++)
            a[i] >>= 1;
        cout << 2*calc() << endl;
	}
	return 0;
}
