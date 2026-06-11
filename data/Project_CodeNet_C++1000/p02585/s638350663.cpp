#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define vii vector<int,int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define umii unordered_map<int,int>
#define mii map<int,int>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a ; i<b ; i++)

const long long MOD = 1e9+7;

void solve() {
	ll n,k;
	cin >> n >> k;
	int p[n], c[n];
	for(int i=0; i<n; i++)
		cin >> p[i];
	for(int i=0; i<n; i++)
		cin >> c[i];
	vector<vector<long long>> cycle, pre;
	for(int i=0; i<n; i++) {
		vector<long long> temp1;
		// temp.pb(p[i]);
		ll s=p[p[i]-1];
		ll score=c[p[i]-1];
		temp1.pb(score);
		while(p[i] != s) {
			// temp.pb(s);
			score+=c[s-1];
			temp1.pb(score);
			s=p[s-1];
		}
		// cycle.pb(temp);
		pre.pb(temp1);
	}
	ll mx=INT_MIN;
	for(auto it:pre) {
		ll score=INT_MIN;
		if(it.size()>=k) {
			for(int i=0; i<k ; i++) {
				score = max(score, it[i]);
			}
		}
		else {
			if(*(it.rbegin()) < 0) {
				for(auto itr:it)
					score = max(score,itr);
			}
			else {
				ll q=k/it.size();
				ll r=k%it.size();
				ll t1 = *(it.rbegin())*q;
				ll t2 = *(it.rbegin())*(q-1);
				ll m = INT_MIN;
				for(int i=0; i<r; i++)
					m = max(m, it[i]);
				t1+=m;
				m=INT_MIN;
				for(int i=0; i<it.size(); i++) {
					m = max(m, it[i]);
				}
				t2+=m;
				score = max(t1, t2);
			}
		}
		mx=max(mx, score);
	}
	cout << mx << endl;
}

signed main() 
{
	int t=1;
	// cin>>t;
	for(int i=1; i<=t; i++) {
		solve();
	}
}