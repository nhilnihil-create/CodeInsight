
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define inp(x) cin>>x
#define print(x) cout<<x
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define reset(d,val) memset(d,val,sizeof(d))
#define sort(v) sort(v.begin(),v.end())
#define sort_arr(arr,i,f) sort(arr+i,arr+f)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

int arr[200005];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int cnt=0;

	int val = 0;
	int pm = 1;
	ll ans = 0;
	arr[val]++;
	for (int i = s.length()-1; i>=0; i--)
	{
		val = (val+pm*(s[i]-'0'))%2019;
		//val%=2019;
		pm = (pm*10)%2019;
		ans += arr[val];
		arr[val]++;
	}
	cout<<ans;
	return 0;

}
