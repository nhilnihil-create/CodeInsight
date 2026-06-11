#include <bits/stdc++.h>

using namespace std;

#define IOS 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld			long double
#define ll 			long long
#define ull			unsigned long long
#define si(a)			a.size()
#define pb			push_back
#define mp			make_pair
#define F			first
#define S			second
#define lb			lower_bound
#define ub			upper_bound
#define deb(x)			cout<<"#x "<<x<<"\n";
#define trace(x,y)		cout<<"#x "<<x<<" #y "<<y<<"\n";
#define cn			cout<<"\n";
#define mod			1000000007


bool SBF(const pair<int,int>& a, const pair<int,int>& b){return a.F < b.F;}

bool SBS(const pair<int,int>& a, const pair<int,int>& b){return a.S < b.S;}



ll power(ll x, ll y){
	ll res = 1;
	x = x%mod;
	while(y){
	 	
                if(y&1)res = (res*x)%mod;
		y = y >> 1;
		x = (x*x)%mod;
	}
	return res;
}
ll modInv(ll x){
	return power(x , mod - 2);
}


const int INF = 1e9;





void solve(){ 
     string s, t;
     cin >> s  >> t;
     
     int n = s.length();
     int m = t.length();
     ll ans = m;
     for(int i = 0 ;i <= n - m; i++){
	     int diff = 0;
	     for(int j = 0 ;j < m;j++){
		     if(t[j]  != s[i+j])diff++;
	     }
	     ans = min(ans,diff*1LL);
     }
     cout<<ans<<"\n";




}











int main(){

    solve();

}














