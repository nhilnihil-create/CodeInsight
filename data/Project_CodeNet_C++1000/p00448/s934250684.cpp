#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<string>
#include<cstdio>
#include<stack>
#include<cmath>
#include<bitset>
#include<memory>
#include<memory.h>
#include<utility>
#include<map>
using namespace std;
#define FOR(i,m,n) for(i=m;i<n;i++)
#define CLR(a,b) memset(a,b,sizeof(a))
#define ROF(i,m,n) for(i=m;i>=n;i--)
#define BUG cout<<"debug"<<endl;
#define RT return
#define BK break
#define HEAP priority_queue
#define SP " "
#define rd(x) (rand()%(x))
#define lowf(a,b,c) lower_bound(a,b,c)
#define upf(a,b,c) upper_bound(a,b,c)
#define sh(a) cout<<a<<endl
typedef long long LL;
typedef vector<int> VI;
const int INF = 2147483647;
const int NEN = -INF - 1;
const LL LINF = 9223372036854775807;
bitset<10005> Map[12];
int ord[10];
int R, C,i,j,k,ans,sum,ANS;//C是高，R是宽
int main()
{
	int temp;
	while (cin >> C >> R)
	{
		CLR(ord, 0);
		if (C == 0 && R == 0)break;
		ans = 0;
		FOR(i, 0, C)
		{
			FOR(j, 0, R)
			{
				cin >> temp;
				Map[i][j] = temp;
			}
		}
		ANS = 0;
		FOR(j, 0, R)
		{
			sum = 0;
			FOR(i, 0, C)
			{
				sum += Map[i][j];
			}
			ANS += max(sum, C - sum);
		}
		ans = ANS;
		FOR(i, 0, C)
		{
			sort(ord, ord + C);
			ord[C - 1 - i] = 1;
			do
			{
				ANS = 0;
				FOR(j, 0, C)
				{
					if (ord[j] == 1)Map[j].flip();
				}
				FOR(j, 0, R)
				{
					sum = 0;
					FOR(k, 0, C)
					{
						sum += Map[k][j];
					}
					sum = max(sum, C - sum);
					ANS += sum;
				}
				ans = max(ans, ANS);
				FOR(j, 0, C)
				{
					if (ord[j] == 1)Map[j].flip();
				}
			} while (next_permutation(ord, ord + C));
		}
		cout << ans << endl;
	}
}
