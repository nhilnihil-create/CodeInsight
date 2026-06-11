		#include <bits/stdc++.h>
		using namespace std;
		typedef long long ll;
		#define PRINT(x,y) cout<<"Case #"<<(int)x<<": "<<(int)(y)<<endl;
		ll exp(ll x, ll y) {
			if(y==0) return 1;
			if(y==1) return x;
			if(y%2==0) return exp(x,y/2)*exp(x,y/2);
			else return x*exp(x,y/2)*exp(x,y/2);
		}
		ll gcd(ll a , ll b) {
			if(b==0) return a;
			return gcd(b , a%b);
		}
		ll lcm(ll a , ll b) {
			return (a*b)/gcd(a,b);
		}
		#define vec(n) vector<int> v((int)(n),0);
		#define vecl(n) vector<ll> v((ll)(n),0);
		#define sq(a) ((int)(a))*((int)(a));
		#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		int l;
		ll fact(ll x) {
			if(x==1) return 1;
			else return x*fact(x-1);
		}
		bool isPrime(int x) {
			int ans  = 0;
			for(int i=2;i<=sqrt(x);++i) {
				if(x%i==0) {
					ans = 1; i=x;
				}  
			}
			if(ans==0) return true;
			else return false;
		}
		ll isPerfect(ll x) {
			double y = sqrt(x);
			return (floor(y)==ceil(y));
		} 

		int z = 0;
		void ask(int x, int y) {
			cout<<"? "<<x<<" "<<y<<endl;
			}

		void solve() {
		string s; cin>>s;
		ll ans = 0;
		for(ll i = 0;i<s.length();++i) {
			ans+=s[i]-'0';
		}
		if(ans%9==0) cout<<"Yes";
		else cout<<"No";


		}			



		int main() {
			io
			 solve();
		}
		    
		