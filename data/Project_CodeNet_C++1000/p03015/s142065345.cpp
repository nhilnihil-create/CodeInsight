#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define MOD 1000000007
#define int ll
string str;

int power(int a,int b,int M){ //returns a^b % M, O(logb)
  	 if (b==0) return 1;
    
   	int half = b/2;
   	int halfval;
    
   	halfval = (power(a,half,M))%M;
   	if (b%2 == 0) return (halfval * halfval) % M;
   	else return (((halfval * halfval) % M) * (a % M)) % M;
}



	

	
int32_t main(){
	fast;
	
	cin>>str;
	
	int ans = 0,prevones = 0;

	FOR(i,0,str.size()-1){
		if (str[i] == '1'){
			ans += (power(2,prevones,MOD) * power(3,str.size() - i - 1,MOD)) % MOD;
			ans %= MOD;
			prevones++;

		}
	}
	cout<<(ans + power(2,prevones,MOD)) % MOD;
	
	
	
}
