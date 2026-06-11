#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define EPS                         1e-9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define MOD                         1000000007
typedef long long ll;
/*For you see , each day i love you
 more.Today more than yesterday
  less than tomorrow.*/
using namespace std;
int dp[101][101];

int main()
{
	int h,w;
	cin>>h>>w;
	
	vector<string> vec;
	
	for(int i = 0;i<h;i++)
	{
		string str;
		cin>>str;
		vec.push_back(str);
	}
	
	if(vec[0][0] == '#') dp[0][0] = 1;
	
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			if(i == 0 && j == 0) continue;
			int val = INF;
			if(i-1 >= 0)
			{
				val = dp[i-1][j];
				if(vec[i-1][j] == '.' && vec[i][j] == '#') val += 1;
			}
			
			if(j-1 >=0)
			{
				int temp = dp[i][j-1];
				
				if(vec[i][j-1] == '.' && vec[i][j] == '#') temp+=1;
				
				val = min(val , temp);
			}
			dp[i][j] = val;		}
	}
	
	cout<<dp[h-1][w-1]<<endl;
	
	return 0;
}