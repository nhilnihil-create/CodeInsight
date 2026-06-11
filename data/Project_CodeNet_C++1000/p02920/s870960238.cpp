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

	bool yes = true;
	vll btree(n2*2-1, 0);
	rep(i, n2*2-1){
		if (btree[i]!=0) continue;
		auto cur = s.end(); cur--;
		if (i!=0){
			cur = s.lower_bound(btree[i-1]);
			cur--;
		}
		if (*cur == -1){
			yes = false;
			break;
		}
		ll I = i;
		do{
			btree[I] = *cur;
			I = I*2+1;
		}while(I<n2*2-1);
		s.erase(cur);
	}

	if (yes){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}