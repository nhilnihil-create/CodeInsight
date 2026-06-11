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
int main()
{
	int n;cin>>n;
	ll sum = 0,ans = 0;
	for(int i=1;i<=n;i++){
		ll c;int d;
		scanf("%d%lld",&d,&c);
		ans += c;
		sum += d*c;
	}
	ans += (sum-1)/9;
	cout << ans-1 << endl;
}
