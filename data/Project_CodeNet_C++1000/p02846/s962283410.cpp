#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	ll t1,t2,a1,a2,b1,b2;

	scanf("%lld %lld", &t1, &t2);
	scanf("%lld %lld", &a1, &a2);
	scanf("%lld %lld", &b1, &b2);
	
	ll p = (a1-b1)*t1;
	ll q = (a2-b2)*t2;

	

	if(p > 0)
	{
		p *= -1;
		q *= -1;
	}

	// cout << p << endl;
	// cout << q << endl;

	// cout << endl;
	// cout << -p << " / " << (p+q) << endl;

	if(p + q == 0)
	{
		printf("infinity\n");
	}

	else if(p+q < 0)
	{
		printf("0\n");
	}

	else
	{
		if(-p % (p+q) == 0)
		{
			printf("%lld\n", (-p)/(p+q)*2);
		}

		else
		{
			printf("%lld\n", (-p)/(p+q)*2+1);
		}
	}

	

	return 0;
}