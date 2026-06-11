#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;

const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

map <pii, ll> mp;
set <pii> s;
int main()
{
	boost;
	int n, d, a, i;
	cin >> n >> d >> a;
	pii arr[n];
	fo(i, 0, n)
	cin >> arr[i].f >> arr[i].s;
	sort(arr, arr + n);
	
	ll curr = 0;
	ll ans = 0;
	fo(i, 0, n) {
		pii p = arr[i];
		while(!s.empty()) {
			auto it = s.begin();
			if(it -> s >= p.f) break;
			
			curr -= mp[*it]; 
			mp[*it] = 0;
			s.erase(it);
		}
		if(curr >= p.s) continue;
		p.s -= curr;
		
		int cnt = (p.s % a ? p.s / a + 1 : p.s / a);
		ans += cnt;
		pii seg = {p.f, p.f + 2 * d};
		mp[seg] = 1ll * cnt * a;
		curr += mp[seg];
		s.insert(seg);
	}
	cout << ans;	
}
