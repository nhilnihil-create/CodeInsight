/*
	Created by : imay_10
	" It won't be EASY, but I'll make it "
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
const ll inf = 1e18;
const double pi = 3.1415926535897932384626;

// Utility for fast exponentiation
ll mpow(ll a,ll b,ll m){
    ll res=1;
    //a%=m;
    while(b){
    	if(b%2) res=res*a%m;
		a=a*a%m;
		b/=2;
	}
	return res;
}

// Utility for modular inverse
ll inv(ll a,ll m){
	return mpow(a,m-2,m);
}

// Utility for GCD Calculation
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

// Utility for binomial coefficient
ll ncr(ll n,ll k)
{
    if(n<k)
        return 0;
    ll C[n + 1][k + 1];
    ll i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if (j==0 || j==i)
                C[i][j]=1;
            else
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    return C[n][k];
}

void solve(){
	//code
	int h, w, m;
	cin >> h >> w >> m;
	vector<pair<int, int>> arr(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i].first >> arr[i].second;
 
	set<pair<int, int>> st;
	for (int i = 0; i < m; i++)
		st.insert(arr[i]);
 
	map<int, int> mpw, mph;
	for (int i = 0; i < m; i++)
		mpw[arr[i].first]++, mph[arr[i].second]++;
 
	int maxw = 0, maxh = 0;
	for (auto x : mpw)
		maxw = max(x.second, maxw);
	for (auto x : mph)
		maxh = max(x.second, maxh);
 
	set<int> stw, sth;
	for (auto x : mpw)
		if (x.second == maxw)
			stw.insert(x.first);
 
	for (auto x : mph)
		if (x.second == maxh)
			sth.insert(x.first);
 
	for (auto x : stw) {
		for (auto y : sth) {
			if (st.find({x, y}) == st.end()) {
				cout << maxw + maxh;
				return ;
			}
		}
	}
	cout << maxw + maxh - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
