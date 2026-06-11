#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n; cin>>n;
	ll n2 = 1<<n;
	multiset<ll> s;
	s.ins(-1);
	rep(i, n2){
		ll temp; cin>>temp;
		s.ins(temp);
	}
	vll u;
	auto itr=s.end(); itr--;
	u.pb(*itr);
	s.erase(itr);
	rep(i, n){
		vll v = u;
		sort(v.begin(), v.end());
		while(v.size()){
			ll par = v.back();
			auto it = s.lower_bound(par); it--;
			if (*it == -1){
				cout << "No\n";
				return 0;
			}
			u.pb(*it);
			v.pop_back();
			s.erase(it);
		}
	}
	cout << "Yes\n";

	return 0;
}