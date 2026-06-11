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

	int n;
	cin>>n;
	string s;
	cin>>s;
	int dp[n-1];
	int check = 0;
	rep(i,n-1){
		int a1 = s[i]-'0';
		int a2 = s[i+1]-'0';
		dp[i] = abs(a2-a1);
		if(dp[i] == 1)check = 1;
	}	
	int c = 0;
	int m = n-2;
	int x = 2;
	while(m/x>0){
		c += m/x;
		x *= 2;
	}
	// cout<<c<<"\n";
	int ans = 0;
	rep(i,n-1){
		int c1 = 0;
		int j = i;
		int x = 2;
		while(j/x > 0){
			c1 += j/x;
			x *= 2;
		}
		j = n-2-i;
		x = 2;
		while(j/x > 0){
			c1 += j/x;
			x *= 2;
		}
		c1 = c - c1;
		// cout<<c1<<" ";
		if(c1 == 0){
			ans ^= dp[i];
		}
	}
	if(ans & 1){
		cout<<1;
		return 0;
	}
	if(check){
		cout<<0;
		return 0;
	}
	rep(i,n-1){
		dp[i] /= 2;
	}
	ans = 0;
	rep(i,n-1){
		int c1 = 0;
		int j = i;
		int x = 2;
		while(j/x > 0){
			c1 += j/x;
			x *= 2;
		}
		j = n-2-i;
		x = 2;
		while(j/x > 0){
			c1 += j/x;
			x *= 2;
		}
		c1 = c - c1;
		// cout<<c1<<" ";
		if(c1 == 0){
			ans ^= dp[i];
		}
	}
	if(ans & 1){
		cout<<2;
	}
	else{
		cout<<0;
	}
	return 0;
}