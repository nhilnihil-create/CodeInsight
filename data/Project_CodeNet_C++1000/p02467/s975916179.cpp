#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ELEM(array) (sizeof (array)/sizeof *(array))
#define MAX_N 1000005
#define MS(m,v) memset(m,v,sizeof(m))
#define SAFE_FREE(ptr) if( ptr != NULL ){ free(ptr); ptr = NULL; }
typedef unsigned int UINT;
typedef long long  ll;
typedef pair<int, int> P;

bool p[1000005];

int main()
{

	REP(i, 1000000) p[i] = true;
	p[0] = p[1] = false;
	for (int i = 2; i*i <= 1000000; i++)
	{
		if (p[i] == true)
		{
			for (int j = 2; j*i <= 1000000; j++)
			{
				p[i*j] = false;
			}
		}
	}
	int n;
	int ncpy;
	cin >> n;
	ncpy = n;
	cout << n << ": ";
	REP(i, 1000000){
		if (p[i]==true)
		{
			while (n%i==0)
			{
				cout << i ;
				n /= i;
				if (n>=i)cout << " ";
			}
		}
	}
	if (n==ncpy)
	{
		cout << n << endl;
	}
	else
	{
		cout << endl;
	}
	return 0;
}