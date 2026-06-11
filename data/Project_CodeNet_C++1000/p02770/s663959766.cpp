// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define msi map<string,int>
#define mii map<int,int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define po pop_back
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int k,q;
	cin>>k>>q;
	vi v(k);
	rep(i,k){
		cin>>v[i];
	}	
	while(q--){
		ll n,x,m;
		ll sum,sum2;
		sum = sum2 = 0;
		cin>>n>>x>>m;
		vi d(k);
		rep(i,k){
			d[i] = v[i] % m;
		}
		ll q = ((n-1)/k);
		ll r = (n-1)%k;
		ll count = 0;
		rep(i,k){
			sum += d[i];
			if(d[i] == 0)count++;
		}
		count *= q;
		rep(i,r){
			if(d[i] == 0)count++;
			/*if(i != r-1)*/sum2 += d[i];
		}
		// sum2 -= v[r-1];
		// cout<<q<<" "<<sum<<"\n";
		ll f = x;
		f += q*sum;
		// cout<<count<<"\n";
		// cout<<f<<" ";
		f += sum2;
		// cout<<f<<" ";
		ll ans2 = f/m - x/m;
		ll ans = q*k + r - ans2 - count;
		cout<<ans<<"\n";
	}
	return 0;
}