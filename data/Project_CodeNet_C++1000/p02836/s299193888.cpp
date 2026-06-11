#include <bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOD(i,a,b) for(int i=a; i>=b; i--)
#define pa pair<int,int>
#define fi first
#define se second
#define MOD xxx
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) ((n^(1<<(i-1))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))

using namespace std;
string s;
int n,ans(0);
int main()
{
    cin >> s;
    n = s.size();
    for(int i = 0; i < s.size(); i++)
    if(s[i]!=s[n-i-1]) ans++;
    cout << ans/2;
	return 0;
}
