#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

LL n;

int main()
{
	cin >> n;
	
	LL res = 1LL;
	
	for (LL i = 1LL; i <= (n - 1LL) / i; i ++ )
		if ((n - 1LL) % i == 0LL)
		{
			if (i > 1LL) res ++ ;
			if ((n - 1LL) / i != i) res ++ ;
		}
		
	for (LL i = 2LL; i <= n / i; i ++ )
		if (n % i == 0LL)
		{
			LL t = n;
			while (t % i == 0LL) t /= i;
			if (t % i == 1LL) res ++ ;
		}
	
	cout << res << endl;
    return 0;
}