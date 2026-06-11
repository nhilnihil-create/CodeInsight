#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,k,c,num=0,cnt[200010];
string s;

int main()
{
	cin>>n>>k>>c>>s;
	int cur=0;
	while(cur<n)
	{
		while(cur<n&&s[cur]=='x') cur++;
		num++;
		cnt[cur]++;
		cur+=c+1;
	}
	if(num>k) return 0;
	cur=n-1;
	num=0;
	while(cur>=0)
	{
		while(cur>=0&&s[cur]=='x') cur--;
		cnt[cur]++;
		cur-=c+1;
	}
	rep(i,n) if(cnt[i]==2) cout<<i+1<<endl;
	return 0;
}