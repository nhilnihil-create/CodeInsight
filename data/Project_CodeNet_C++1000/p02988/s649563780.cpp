// @Author :- Gaurav Bharti
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

ll binpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res * a ; 
		a = a * a ;
		b = b >> 1;
	}

	return res;
}

int main(){
	ItsFUN;

	int n ;cin >> n;

	vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i];
	int ans = 0;

	for(int i = 1; i < n - 1; i++) { 
		if((p[i - 1] < p[i]) && (p[i] < p[i + 1])) ans++; 
		else if((p[i - 1] > p[i]) && (p[i] > p[i + 1])) ans++;
 	}
	cout << ans << endl;


    return 0;
}