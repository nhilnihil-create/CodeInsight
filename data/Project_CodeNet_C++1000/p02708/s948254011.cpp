// JAI SHREE RAM
#pragma GCC optimize("O3")
typedef long long int ll;
typedef unsigned long long int ull;
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define M_PI           3.14159265358979323846  /* pi */
#define sec second
#define fir first
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repe(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define pb push_back
#define pii pair<int,int>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	ll minSum,maxSum;
	for(ll i=k;i<=n+1;i++)
	{
		minSum= (i*(i-1))/2;
		maxSum= ((n+1)*n)/2 - ((n+1-i)*(n-i))/2;
		ans+=maxSum-minSum + 1;
		ans%=1000000007;
	}
	cout<<ans<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve();
  }
  return 0;
}
