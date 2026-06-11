#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 505;
const ll LINF = 1e18 + 5;
int n, k;
int a[N], t[N]; 
bool check(int x)
{
	ll tmp = 0;
	for(int i=1; i<=n; i++) 
		t[i] = a[i]%x;
	sort(t+1, t+n+1);
	int l = 1, r = n;
	while(l<r)
	{
		if(t[l]<x-t[r])
		{
			t[r] += t[l];
			tmp += t[l];
			l++;
		}
		else
		{
			tmp += x - t[r];
			t[l] -= x - t[r];
			r--;
			if(!t[l]) l++;
		}
	}
	return tmp <= k;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> k;
 	int sum = 0;
 	for(int i=1; i<=n; i++) 
	{
		cin >> a[i]; 
		sum += a[i];
	}
	int ans = 0;
	for(int i=1; i*i<=sum; i++)
	{
		if(sum%i) continue; 
		if(check(i) && i>ans) ans = i;
		if(i*i!=sum && check(sum/i) && sum/i>ans) ans = sum/i;
	}
	cout << ans;
	return 0;
}
