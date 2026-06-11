#include <bits/stdc++.h>
#define ll long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int> 
#define vll vector<ll> 
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " - " << x << endl;
const ll MOD = 1e9 + 7;
const ll INF = 1<<29;
const ll MAX_N = 1e6 + 7;
using namespace std;

ll x; 

ll power(ll x, ll y) { 
	ll res = 1;
	while (y > 0) { 
		if (y & 1) 
			res = (res*x) ; 
		y = y>>1;
		x = (x*x); 
	} 
	return res; 
}

bool eqn(ll a,ll b){
    ll temp = (a - b) * ( (power(a,4)) + (power(a,3) * b) + (power(a,2) * power(b,2)) + (a * power(b,3)) + (power(b,4)) ) ;
    // if(temp==x) cout << temp;
    if(temp == x) return true;
    else return false;
}

int main() {
    IOS;
    cin >> x;
    vi v;
    for(int i=1;i*i<=x;++i){
        if(x%i==0){
            v.pb(i);
            if(i!=x/i) v.pb(x/i);
        }
    }
    v.pb(x);
    ll got = 0,j;
    for(auto num:v){
        for(int i=-300;i<=300;++i){
            j = num + i;
            if(eqn(j,i)){
                cout << j << " " << i;
                got = 1;
                break;
            } 
        }
        if(got) break;
    }
}