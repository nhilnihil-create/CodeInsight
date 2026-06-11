#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

int main()
{
	int m,d;
	cin >> m >> d;
	int ans = 0;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=d;j++)
		{
			if((j%10)>=2&&(j/10)>=2)
			if(i==(j%10)*(j/10))
			{
				ans ++ ;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}