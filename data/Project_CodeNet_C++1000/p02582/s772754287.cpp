#include <bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
const int N = 1e5+100;
const int MOD = 1e9+7;

int n,m,T;
string s;
int main()
{
	/*scanf("%d",&T);
	while(T--)
	{
	
	 } 
	 */
	//scanf("%d%d",&n,&m);
	getline(cin,s);
	int cnt = 0,ans = 0;
	for(int i=0;i<3;i++)
	{
		if(s[i] == 'R')	cnt++;
		ans = max(ans,cnt);
		if(s[i] == 'S')	cnt = 0;
	}
	cout << ans << endl;
	
	return 0;
}