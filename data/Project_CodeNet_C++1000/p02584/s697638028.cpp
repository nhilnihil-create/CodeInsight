#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pvec(v) for(auto e: v) cout << e << " ";
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b) for(int i = (a); i<(b); ++i)
#define pb push_back
#define INF 1000000005
#define MOD 1000000007
#define all(v) v.begin(), v.end()

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll power(ll x, ll y, ll p = MOD){  
    ll res = 1LL; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1LL)  
            res = (res*x) % p;
        y = y>>1LL; 
        x = (x*x) % p;  
    }  
    return res;  
}  

int main(){
	IO
	ll x, k, d;
	cin >> x >> k >> d;

	ll req = abs(x)/d;
	if(req > k) {
		if(x < 0) 
			cout << abs(x + k*d) << endl;
		else 
			cout << abs(x - k*d) << endl;
	}
	else {
		if(x < 0) 
			x+=req*d;
		else 
			x-=req*d;
		k-=req;

		if(k%2LL) {
			if(x < 0) x+=d;
			else x-=d;
		}
		cout << abs(x) << endl;
	}
	return 0;
}