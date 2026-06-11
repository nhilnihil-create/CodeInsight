#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<map>
typedef long long int ll;
using namespace std;
#define maxn 0x3f3f3f3f
const int mm=1e2;
ll d[mm];
ll dd[mm];
int vis[mm];
vector<ll> v;
int main()
{
	ll i,j,ss;
	string s;
	cin>>s; ss=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='h'&&s[i+1]=='i')
		{
			i++;
			continue;
		}
		else
		ss=1;
	}
	if(ss)
	printf("No\n");
	else
	printf("Yes\n");
	
}