#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
#define MAXIM 1000003

ll mod = 1e9 + 7;


void solve(){ 
    ll n;
    cin >> n;
    ll c = 0;
    bool found = false;
    rep(i,0,n){
        ll a,b;
        cin >> a >> b;
        if(a == b) c++;
        else if(a != b) c=0;
        if(c == 3) found = true;
    }
    if(found) cout << "Yes" << br;
    else cout << "No" << br;
}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	ll t = 1;
	// cin >> t;
	rep(i,0,t){
		solve();
	}
 
}	