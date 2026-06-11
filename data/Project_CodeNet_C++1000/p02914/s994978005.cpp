#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#define MAXN 1000
using namespace std;
typedef long long ll;
inline ll rd() {ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
ll num[200000];
ll cnt;
ll loc[64]={0};
void insert(ll value) {
	for (ll i = 61; i >= 0; i--) {
		if ((value >> i) & 1) {
			if (!loc[i]) {
				loc[i] = value;
				return;
			} else
				value ^= loc[i];
		}
		if (!value)
			return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	//freopen("../in", "r", stdin);
	//freopen("../out", "w", stdout);
	cin >> cnt;
	ll all = 0;
	for (ll i = 0; i < cnt; i++) {
		cin >> num[i];
		all ^= num[i];
	}
	for (ll i = 0; i <= 60; i++) {
		if((all>>i)&1) {
			for (ll j = 0; j < cnt; j++)
				if ((num[j] >> i) & 1)
					num[j] -= (1ll << i);
		}
	}
	for(ll i=0;i<cnt;i++)
		insert(num[i]);
	ll ans=0;
	for(ll i=60;i>=0;i--)
	{
		if((ans^loc[i])>ans)
			ans=ans^loc[i];
	}
	cout<<(ans+(ans^all))<<endl;
	return 0;
}