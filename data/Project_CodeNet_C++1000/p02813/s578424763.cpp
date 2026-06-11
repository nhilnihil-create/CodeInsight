// @Author :- Gaurav Bharti
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test int t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
const int MIN = INT_MIN;
const int MAX = INT_MAX;

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
	return (a.second < b.second) ;
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res * a;
		a = a*a;
		b = b >> 1;
	}

	return res;
}


/*
BHAI EFFORT DAAL
*/


int main(){
	ItsFUN;

	int n; cin >> n;
	vii a(n),b(n),c(n);

	for(int i = 0; i < n; ++i) {
		c[i] = i+1;
	}

	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;

	if(a==b) {
		cout << 0 << "\n";
		return 0;
	}

	int cnt = 0, l = 0, r = 0;
	do{
		if(c == a) {
			l = cnt; 
		}
		else if( c == b) {
			r = cnt;
		}
		++cnt;
	}while(next_permutation(c.begin(),c.end()));

	cout << abs(r-l) << "\n";

	return 0;
}