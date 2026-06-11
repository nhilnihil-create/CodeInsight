// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first		
#define se second
#define pb push_back
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
	string s;
	cin >> s;
	int n=s.length();
	reverse(all(s));
	int ten = 1; int ans = 0; int cur = 0;
	map<int,int>mp;
	mp[0]++;
	for(int i=0; i<n; i++){
		cur = (cur+(s[i]-'0')*ten%2019)%2019;
		ten = (ten*10)%2019;
		ans += mp[cur];
		mp[cur]++;
	}
	cout << ans << endl;
}	
