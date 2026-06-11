#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,p; string s;
	cin >> n >> p >> s;
	if(p==2||p==5){
		ll ans = 0;
		for(int i=0; i<n; i++)
			if((s[i]-'0')%p==0)
				ans+=i+1;
		cout << ans << endl;
		return 0;
	}
	map<int,int>mp;
	mp[0]++;
	ll now = 0, ten = 1;
	ll ans = 0;
	for(int i=n-1; i>=0; i--){
		now = (now+(s[i]-'0')*ten)%p;
		ans += mp[now];
		mp[now]++;
		ten = (ten*10)%p;
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
