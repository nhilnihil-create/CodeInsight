#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
int a[maxn];
int main()
{
	int n;cin>>n;
	ll k;cin>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll ans = 0;
	ll tmp = (k*(k-1)/2) % mod;
	for(int i=1;i<=n;i++){
		int x = 0,y = 0;
		for(int j=1;j<=n;j++)
			if(a[j]<a[i])x++;
		for(int j=i+1;j<=n;j++)
			if(a[j]<a[i])y++;
		ans = (ans+y*k+x*tmp) % mod;
	}
	cout << ans << endl;
}
